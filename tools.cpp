#include "tools.h"
#include "ui_tools.h"
#include <QProcess>
#include "config.h"
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include <QClipboard>

Tools::Tools(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Tools)
{
    ui->setupUi(this);
    QStringList items;
    items << "FR" << "PR" << "CR";
    ui->issue->addItems(items);
}

Tools::~Tools()
{
    delete ui;
}

void Tools::changeEvent(QEvent *e)
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

void Tools::on_pushButton_clicked()
{
    QProcess *process = new QProcess;
    QString sdkPath = Config::getSdkPath();
    qDebug() <<sdkPath;
    if(!sdkPath.isNull()){
        QString hierarchyviewer = sdkPath.append("/tools/hierarchyviewer");
        if(QFile::exists(hierarchyviewer)){
            process->start(hierarchyviewer);
        }else{
            QMessageBox::warning(this,"sdk_path is error!","Please reset the sdk_path",QMessageBox::Yes,QMessageBox::Yes);
        }

    }else{
        QMessageBox::warning(this,"sdk_path dont exists!","Please set the sdk_path",QMessageBox::Yes,QMessageBox::Yes);
    }

}

void Tools::on_ddms_clicked()
{
    QProcess *process = new QProcess;
    QString sdkPath = Config::getSdkPath();
    qDebug() <<sdkPath;
    if(!sdkPath.isNull()){
        QString ddms = sdkPath.append("/tools/ddms");
        if(QFile::exists(ddms)){
            process->start(ddms);
        }else{
            QMessageBox::warning(this,"sdk_path is error!","Please reset the sdk_path",QMessageBox::Yes,QMessageBox::Yes);
        }

    }else{
        QMessageBox::warning(this,"sdk_path dont exists!","Please set the sdk_path",QMessageBox::Yes,QMessageBox::Yes);
    }
}

void Tools::on_cp1_clicked()
{
    QClipboard * clipboard = QApplication::clipboard();
    clipboard->setText(ui->note_1->text());
}

void Tools::on_cp2_clicked()
{
    QClipboard * clipboard = QApplication::clipboard();
    clipboard->setText(ui->note_2->text());
}

void Tools::on_cp3_clicked()
{
    QClipboard * clipboard = QApplication::clipboard();
    clipboard->setText(ui->note_3->text());
}


void Tools::on_issue_activated(QString issue)
{
    if(issue == "FR" || issue == "CR")
        issue = "[FEATURE]";
    else
        issue = "[BUGFIX]";
    QString name = Config::getName();
    QString time = QDateTime::currentDateTime().toString("MM/dd/yyyy");
    QString note_1 = QString("//").append(issue).append("-Add-BEGIN by TSCD.")
                     .append(name.trimmed()).append(",").append(time).append(",")
                     .append(ui->bug_id->text().trimmed()).append(",").append(ui->des->text().trimmed());
    QString note_2 = QString("//").append(issue).append("-Add-END by TSCD.").append(name.trimmed());
    //22 space
    int name_length = name.trimmed().length();
    int ext_length = 22 - name_length;
    int space_length;
    bool odd;
    QString space_bef;
    QString space_end;
    if(ext_length >0)
    {
        space_length = ext_length/2;
        if(!ext_length%2)
        {
            odd = true;
        }
        for(int i=0;i<space_length;i++){
            space_bef += " ";
        }
        if(odd){
            space_end = space_bef;
            space_end += " ";
        }else{
            space_end = space_bef;
        }
    }
    // 18 char
    QStringList tmp_list = ui->des->text().trimmed().split(" ");
    QStringList lines;
    lines << "";
    for(int i=0;i<tmp_list.size();i++){
        QString s = tmp_list.at(i);
        QString line = lines.last();
        if(line.size() + s.size() + 1 <= 18){
            if(line.size() != 0){
                line.append(" ");
            }
            line.append(s);
            if(i== tmp_list.size() - 1)
                line = addSpace(18-line.size(),line);
            lines.replace(lines.size()-1,line);
        }else{
            int space = 18 - line.size();
            if(line.size() == 0){
                lines.replace(lines.size()-1,s);
            }else{
                line = addSpace(space,line);
                lines.replace(lines.size()-1,line);
                if(line.size())
                lines << s;
            }
            if(i== tmp_list.size() - 1){
                s = addSpace(18-s.size(),s);
                lines.replace(lines.size()-1,s);
            }
        }
    }

    QString note_3 = QString("/* ").append(time).append("|").append(space_bef).append(name.trimmed()).append(space_end).append("|        ")
                     .append(ui->bug_id->text().trimmed()).append("        |");
    for(int i=0;i<lines.size();i++){
        if(i != 0){
            note_3.append(MID);
        }
        note_3.append(lines.at(i)).append("*/\n");
    }
    note_3.append(END);
    //qDebug() << note_3;
    ui->note_1->clear();
    ui->note_1->insert(note_1);
    ui->note_1->selectAll();
    ui->note_2->clear();
    ui->note_2->insert(note_2);
    ui->note_3->clear();
    ui->note_3->insert(note_3);
}

QString Tools::addSpace(int count,QString s){
    for(int j=0;j<count;j++){
        s.append(" ");
    }
    return s;
}
