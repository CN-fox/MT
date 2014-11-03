#include "config.h"
#include "ui_config.h"
#include <QDebug>
#include "opt/cJSON.h"

Config::Config(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Config)
{
    ui->setupUi(this);
    QPushButton *product_select = ui->product_select;
    QPushButton *sdk_select = ui->sdk_select;

    connect(product_select,SIGNAL(clicked()),this,SLOT(openDir()));
    connect(sdk_select,SIGNAL(clicked()),this,SLOT(openSdk()));

    init();
}

Config::~Config()
{
    delete ui;
}

void Config::init()
{
    QString productPath = getProductPath();
    ui->product_path->insert(productPath);
    if(!productPath.isEmpty() && checkProductPath(productPath)){

    }
    ui->sdk_path->insert(getSdkPath());
    ui->email->insert(getEmail());
    ui->name->insert(getName());
}

void Config::changeEvent(QEvent *e)
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

void Config::openDir()
{
    QString dirPath = QFileDialog::getExistingDirectory();
    if(QFile::exists(dirPath))
    {
        qDebug() << dirPath;
        ui->product_path->clear();
        ui->product_path->insert(dirPath);
    }
}

void Config::openSdk()
{
    QString sdkPath = QFileDialog::getExistingDirectory();
    if(QFile::exists(sdkPath)){
        qDebug() << sdkPath;
        ui->sdk_path->clear();
        ui->sdk_path->insert(sdkPath);
    }
}

void Config::on_save_accepted()
{
    QString sdk_path = ui->sdk_path->text().trimmed();
    QString product_path = ui->product_path->text().trimmed();
    QString name = ui->name->text();
    QString email = ui->email->text();

    cJSON *json;
    json = cJSON_CreateObject();
    cJSON_AddStringToObject(json,"product_path",product_path.toAscii().data());
    cJSON_AddStringToObject(json,"sdk_path",sdk_path.toAscii().data());
    cJSON_AddStringToObject(json,"name",name.toAscii().data());
    cJSON_AddStringToObject(json,"email",email.toAscii().data());
    qDebug() << cJSON_Print(json);

    QString config_dir = createDir();

    QString config_path = config_dir.append("/config");
    QFile *config_file = new QFile(config_path);
    config_file->open(QFile::WriteOnly|QFile::Truncate);
    QTextStream out(config_file);
    out << cJSON_Print(json);
    out.flush();
    emit config_change();
}

QString Config::createDir()
{
    QString config_dir = QDir::homePath().append("/.MT");
    QDir *dir = new QDir(config_dir);
    if(!dir->exists())
    {
        bool b = dir->mkpath(config_dir);
        if(b){
            qDebug() <<"success";
        }else{
            qDebug() << "error";
        }

    }
    QString script(config_dir);
    script.append("/build.sh");
    qDebug() << script;
    if(!QFile::exists(script)){
        QFile *script_file = new QFile(script);
        script_file->open(QFile::WriteOnly|QFile::Truncate);
        QTextStream out(script_file);
        QStringList list;
        list << "adb reboot-bootloader";
        list << "/opt/bin/fastboot flash boot $1/boot.img";
        list << "/opt/bin/fastboot flash system $1/system.img";
        list << "/opt/bin/fastboot flash userdata $1/userdata.img";
        list << "/opt/bin/fastboot flash custpack $1/custpack.img";
        list << "/opt/bin/fastboot reboot";
        out << list.join("\n");
        out.flush();
    }
    return config_dir;
}

void Config::createBuildScript()
{

}

bool Config::checkProductPath(const QString path)
{
    if(path.isEmpty())
        return false;
    QString makeFile = path;
    makeFile.append("/Makefile");
    if(QFile::exists(makeFile))
        return true;
    return false;
}

QFile * Config::getconfigFile()
{
    return new QFile(QDir::homePath().append("/.MT/config"));
}

QString Config::getValue(char* key,QString def=""){
    QFile *file = getconfigFile();
    if(QFile::exists(file->fileName())){
        if(file->open(QIODevice::ReadOnly|QIODevice::Text)){
            QTextStream in(file);
            QByteArray all = in.readAll().toLatin1();
            cJSON *root = cJSON_Parse(all.data());
            //set static path value
            cJSON *value = cJSON_GetObjectItem(root,key);
            if(!value || QString(value->valuestring).isEmpty()){
                return def;
            }
            return QString(value->valuestring);
        }
    }
    return def;
}

QString Config::getSdkPath()
{
    return getValue("sdk_path");
}

QString Config::getProductPath()
{
    return getValue("product_path");
}

QString Config::getEmail()
{
    return getValue("email");
}

QString Config::getName()
{
    return getValue("name");
}

QString Config::getPWD()
{
    return getValue("pwd","Tt123456");
}

bool Config::getDebug(){
    return getValue("debug").size()>0;
}

QString Config::getScript()
{
    QString config_dir = QDir::homePath().append("/.MT");
    QString script(config_dir);
    script.append("/build.sh");
    qDebug() << script;
    if(!QFile::exists(script)){
        QFile *script_file = new QFile(script);
        script_file->open(QFile::WriteOnly|QFile::Truncate);
        QTextStream out(script_file);
        QStringList list;
        list << "adb reboot-bootloader";
        list << "/opt/bin/fastboot flash boot $1/boot.img";
        list << "/opt/bin/fastboot flash system $1/system.img";
        list << "/opt/bin/fastboot flash userdata $1/userdata.img";
        list << "/opt/bin/fastboot flash custpack $1/custpack.img";
        list << "/opt/bin/fastboot reboot";
        out << list.join("\n");
        out.flush();
    }
    return script;
}
