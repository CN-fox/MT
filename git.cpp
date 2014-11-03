#include "git.h"
#include "ui_git.h"
#include "config.h"
#include <QDebug>
#include <QMessageBox>
#include <pushcode.h>
#include <QInputDialog>
#include <QApplication>

Git::Git(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Git)
{
    ui->setupUi(this);
    process = new QProcess;
    task = new QLinkedList<QString>();
    process->setProcessChannelMode(QProcess::MergedChannels);
    connect(process,SIGNAL(readyRead()),this,SLOT(read()));
    connect(process,SIGNAL(finished(int)),this,SLOT(finished(int)));
    init();
}

Git::~Git()
{
    process->close();
    delete ui;
}

void Git::config_change()
{
    init();
}

void Git::init()
{
    QString path = Config::getProductPath();
    if(QFile::exists(path))
    {
        process->setWorkingDirectory(path);
        QString product_name = path+="/.repo/manifest.xml";
        if(QFile::exists(product_name)) {
            QString *errorStr;
            int errorLine;
            int errorCol;
            if(!doc.setContent(new QFile(product_name),true,errorStr,&errorLine,&errorCol)) {
                qDebug () << errorStr << errorLine << errorCol;
            } else {
                QDomNode root = doc.childNodes().at(1);
                QDomNodeList manifest = root.childNodes();
                for(int i=0;i<manifest.count();i++){
                    QDomNode node = manifest.at(i);
                    QDomNamedNodeMap attrs = node.attributes();
                    map.insert(attrs.item(0).nodeValue(),attrs.item(1).nodeValue());
                }
            }
        }
        QString out_dir = Config::getProductPath()+=OUT;
        QDir *dir = new QDir(out_dir);
        dir->setFilter(QDir::NoDotAndDotDot|QDir::AllDirs);
        products =  dir->entryList();
        products.removeOne("Common");
        products.removeOne("generic");

        QString script = Config::getScript();
        if(QFile::exists(script)){
            QString com("chmod +x ");
            com.append(script);
            system(com.toLatin1().data());
        }

        qDebug() << "git init success";
    }


}

void Git::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Git::updateText(QString in)
{
    ui->textEdit->insertPlainText(in.toLatin1());
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
}

void Git::finished(int code)
{
    if(task->size() >0){
        qDebug() << task->first();
        command(task);
    }else{
        qDebug() << "finish";
    }
}

void Git::read()
{
    char buf[1024];
    do{
        process->readLine(buf,sizeof(buf));
        updateText(tr(buf));
    }while(process->canReadLine());
}

QLinkedList<QString> * Git::getTask()
{
    return task;
}

void Git::on_search_clicked()
{
    ui->select->clear();
    QList<QString> list =  map.keys();
    for(int i = 0;i<list.size();i++){
        if(list.at(i).endsWith(ui->product_name->text()))
            ui->select->insertItem(i,list.at(i));
    }

    if(ui->select->count() == 1){
        module = Config::getProductPath().append("/")
                 .append(ui->select->itemText(0));
        process->setWorkingDirectory(module);
        module_name = ui->product_name->text();
    }else if(ui->select->count()>1){
        module_name = ui->product_name->text();
    }
}

void Git::on_select_activated(QString path)
{
    module = Config::getProductPath().append("/").append(path);
    qDebug() << module;
    process->setWorkingDirectory(module);
}

void Git::on_diff_clicked()
{
    QString com = "git diff";
    updateText(com+="\n");
    command(com);
}

void Git::command(QString com)
{
    process->start(com);
}

void Git::command(QLinkedList<QString> *task,bool print)
{
    if(task->size()>0){
        QString com = task->first();
        if(print)
           updateText(com+="\n");
        else
            qDebug() << com;
        command(com);
        task->removeFirst();
    }
}

bool Git::pushApk(const QString product_root)
{
    QStringList dirs;
    dirs << APP << VENDOR << PRIV << WITHOUTLIBS << CUSTPACK_F;
    mP.clear();
    mP = getModuleName();
    foreach(QString dir,dirs){
        QString app = product_root;
        foreach(moduleProduct m,mP){
            if(m.type == ".jar"){
                app = product_root;
                app.append("/system/framework/").append(m.name).append(m.type);
                qDebug() << app;
                if(QFile::exists(app)){
                    task->append("adb remount");
                    QString command;
                    command = QString("adb push ").append(app).append(' ').append("/system/framework/");
                    task->append(command);
                    if(m.name == mP.last().name){
                        task->append("adb reboot");
                        return true;
                    }
                    continue;
                }else{
                    return false;
                }
            }
            app = app.append(dir).append(m.name).append(m.type);
            if(QFile::exists(app)){
                QString command;
                QString res = product_root;
                res = res.append(CUSTPACK).append(m.name).append("-res.apk");
                if(QFile::exists(res)){
                    //TODO //FIXME for different product the command is diff
                    task->append(QString("adb shell mount -o remount -t ext4 /dev/block/bootdevice/by-name/custpack /custpack"));
                    command = QString("adb push ").append(res).append(' ').append(CUSTPACK).append(ui->product_name->text()).append("-res.apk");
                    task->append(command);
                    qDebug() << res;
                }
                if(dir == WITHOUTLIBS){
                    command = QString("adb install -r ").append(app);
                    task->append(command);
                }else{
                     task->append(QString("adb remount"));
                     command = QString("adb push ").append(app).append(' ').append(dir);
                     task->append(command);
                }
                return true;
            }
        }
    }
    return false;
}

QList<moduleProduct> Git::getModuleName()
{
    if(mP.size()>0)
        return mP;
    QList<moduleProduct> out;
    moduleProduct p;
    const QString modulePath = Config::getProductPath().append("/")+=ui->select->currentText();
    QString smk = QString(modulePath).append("/Android.mk");
    if(QFile::exists(smk)){
        QFile *file = new QFile(smk);
        if(file->open(QIODevice::ReadOnly|QIODevice::Text)){
            QTextStream in(file);
            QString line;
            do{
                line = in.readLine();
                if(!line.isNull()){
                    QStringList tmp = line.split(" := ");
                    if(tmp.at(0) == LOCAL_PACKAGE_NAME){
                        p.name = tmp.at(1);
                        p.type = ".apk";
                        out << p;
                    }else if(tmp.at(0) == "LOCAL_MODULE"){
                        p.name = tmp.at(1);
                    }else if(tmp.at(0) == "LOCAL_MODULE_CLASS" && tmp.at(1) == "JAVA_LIBRARIES"){
                        p.type = ".jar";
                        out << p;
                    }
                }
            }while(!line.isNull());
        }
    }else{
        p.name = ui->product_name->text();
        p.type = ".apk";
        out << p;
    }
    qDebug() << out.size();
    return out;
}

void Git::on_push_apk_clicked()
{
    QString path = Config::getProductPath()+=OUT;
    if(products.size() == 0){
        QMessageBox::warning(this,"","product not find",QMessageBox::Yes,QMessageBox::Yes);
    }else if(products.size() ==1){
        productName = products.at(0);
        if(pushApk(path.append(productName)))
            command(task);
        else{
            qDebug() << "error";
            QMessageBox::warning(this,"error","some error happen");
        }
    }else{
        bool ok;
        QString item = QInputDialog::getItem(this, tr("Select product"),tr("Products:"), products, 0, false, &ok);
        if (ok && !item.isEmpty()){
            qDebug() << item;
            if(pushApk(path.append(productName)))
                command(task);
            else{
                qDebug() << "error";
                QMessageBox::warning(this,"error","some error happen");
            }

        }
    }
}

void Git::on_tcpdump_clicked()
{
    if(process->isOpen()){
        process->close();
        ui->tcpdump->setText("tcpdump");
    }else{
        ui->tcpdump->setText("Runing!");
        task->clear();
        task->append("adb shell tcpdump -i any -p -s 0 -w sdcard/log.pcap");
        QString pull = QString("adb pull sdcard/log.pcap ").append(QDir::homePath()).append("/");
        task->append(pull);
        command(task);
    }
}

void Git::on_push_rom_clicked()
{
    task->clear();
    QString script = Config::getScript();
    QString com(script);
    QString out(Config::getProductPath());
    out.append(OUT);
    com.append(" ").append(out).append(products.at(0));
    //qDebug() << com;
    command(com);
}

void Git::on_make_clicked()
{
    QStringList env =QProcess::systemEnvironment();
    QStringList mPath;
    mPath << "TARGET_BUILD_TYPE=release" << "TARGET_PRODUCT=alto4.5" << "TARGET_BUILD_VARIANT=eng";
    mPath << "TARGET_BUILD_CUSTOM_IMAGES=false" << "TARGET_BUILD_MMITEST=false" <<"JAVA_HOME=/opt/java/lastest";
    mPath << "TARGET_GCC_VERSION=4.7" << "ANDROID_EABI_TOOLCHAIN=/home/zhongke/code/8916/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.7/bin";
    mPath << "ANDROID_TOOLCHAIN=/home/zhongke/code/8916/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.7/bin";
    mPath << "ANDROID_QTOOLS=/home/zhongke/code/8916/development/emulator/qtools"
            << "ANDROID_DEV_SCRIPTS=/home/zhongke/code/8916/development/scripts:/home/zhongke/code/8916/prebuilts/devtools/tools"
            << "ANDROID_BUILD_PATHS=/home/zhongke/code/8916/out/host/linux-x86/bin:/home/zhongke/code/8916/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.7/bin:/home/zhongke/code/8916/prebuilts/gcc/linux-x86/arm/arm-eabi-4.7/bin:/home/zhongke/code/8916/prebuilts/gcc/linux-x86/mips/mipsel-linux-android-4.7/bin:/home/zhongke/code/8916/development/emulator/qtools:/home/zhongke/code/8916/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.7/bin:/home/zhongke/code/8916/prebuilts/gcc/linux-x86/arm/arm-eabi-4.7/bin:/home/zhongke/code/8916/development/scripts:/home/zhongke/code/8916/prebuilts/devtools/tools:"
            << "ANDROID_JAVA_TOOLCHAIN=/opt/java/lastest/bin"
            << "ANDROID_PRODUCT_OU=/home/zhongke/code/8916/out/target/product/alto45"
            << "OUT=/home/zhongke/code/8916/out/target/product/alto45"
            << "ANDROID_HOST_OUT=/home/zhongke/code/8916/out/host/linux-x86"
            << "OPROFILE_EVENTS_DIR=/home/zhongke/code/8916/external/oprofile/events";
    env << mPath;
    process->setEnvironment(env);
    if(Config::getDebug()){
       command("sh /home/zhongke/test.sh");
    }else{
        QMessageBox::warning(this,"can't debug","not debug mode");
    }

}

void Git::on_push_code_clicked()
{
    PushCode *p = new PushCode(this);
    p->show();
}

void Git::keyPressEvent(QKeyEvent *k)
{
    if(k->key() == Qt::Key_Enter || k->key() == Qt::Key_Return){
        //enter pressed
        //QApplication::focusWidget();
        if(ui->product_name->hasFocus()){
            on_search_clicked();
        }else if(ui->command_text->hasFocus()){
            on_run_clicked();
        }
    }
}

void Git::on_run_clicked()
{
    QString com = ui->command_text->text();
    if(com.isNull()){
        return;
    }else{
        updateText(com+="\n");
        command(com);
    }
    ui->command_text->clear();
}
