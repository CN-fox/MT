#include "test.h"
#include "ui_test.h"
#include <QDebug>
#include <QUrl>
#include <QNetworkRequest>
#include <QTableWidget>
#include "config.h"
#include "opt/xmlhelper.h"
#include <QMessageBox>

Test::Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    QTableWidget *tableWidget = ui->tableWidget;
    //tableWidget->setRowCount(10);
    tableWidget->setEnabled(false);

    search_title = new QList<QString>();
    search_href = new QList<QString>();
    bugs = new QList<Bug*>();
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));
}

Test::~Test()
{
    delete ui;
}

bool finish = true;

void Test::changeEvent(QEvent *e)
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

bool s =true;
QStringList head;
void Test::finished(QNetworkReply * reply)
{
    finish = true;
    if(!s){
        char buf[1024];
        QStringList allBug;
        QStringList singleBug;
        QStringList head;
        bool isBug = false;
        bool isHead = false;
        bool headBegin = false;
        while(reply->readLine(buf,sizeof(buf)) > 0){
            QString b(buf);
            if(b.contains("bz_buglist")){
                isHead = true;
            }

            if(isHead){
                if(b.contains("<tr")){
                    headBegin = true;
                }
                if(headBegin)
                    head << b;
                if(b.contains("</tr>")){
                    isHead = false;
                    QStringList list = XMLHelper::getValueFromString(head.join(""));
                    ui->tableWidget->setColumnCount(8);
                    ui->tableWidget->setHorizontalHeaderLabels(list);
                    ui->tableWidget->setEnabled(true);
                    //qDebug() << list.join(" ");
                    head = list;
                    continue;
                }
            }


            if(b.contains("<td class=\"first-child\">")){
                isBug = true;
                Bug *bug = Bug::getEmpty();
                bug->head = head;
                bugs->append(bug);
            }

            if(isBug){
                if(b.contains("</tr>")){
                    isBug = false;
                    singleBug.insert(0,"<tr>");
                    singleBug.append("</tr>");
                    allBug << singleBug.join("");
                    QStringList list = XMLHelper::getValueFromString(singleBug.join(" "));
                    list.removeAt(1);
                    //qDebug() << list.join(" ");
                    bugs->last()->value = list;
                    singleBug.clear();
                    continue;
                }else if(b.contains("</table>")){

                    break;
                }
                singleBug << b.trimmed();
            }
        }
        qDebug() << bugs->size() << "bugs size";
        ui->tableWidget->setRowCount(bugs->size());
        for(int i = 0;i < bugs->size();i++){
            Bug *bug = bugs->at(i);
            if(bug->value.size()!=bug->head.size()){
                bug->value.insert(6,"");
            }
            for(int j=0;j<bug->value.size();j++){
                 QTableWidgetItem *item = new QTableWidgetItem(bug->value.at(j));
                 //item->
                ui->tableWidget->setItem(i,j,item);
            }
        }
        qDebug() << "load end";
    }
    if(s){
        s= false;
        char buf[1024];
        bool BREAK = false;
        QStringList tt;
        while(reply->readLine(buf,sizeof(buf)) > 0){
            if(QString(buf).contains("href=\"http://bugzilla.tcl-ta.com/\"")){
               while(reply->readLine(buf,sizeof(buf)) > 0){
                    QString b(buf);
                    if(b.trimmed().length() >0){
                        if(b.contains("Administration")){
                            BREAK = true;
                            break;
                        }
                        if(b.contains("title") || b.contains("href")){
                            QStringList tmp = b.split("=");
                            QString key = ((QString)tmp.at(0)).trimmed();
                            tmp.removeAt(0);
                            QString value = tmp.join("=").trimmed();
                            int value_length = value.length();
                            if(value_length>2){
                                value = value.right(value_length-1).left(value_length-2);
                            }
                            if(key == "title"){
                                search_title->append(value);
                            }else if(key == "href"){
                                search_href->append(value.left(value.length()-1));
                            }
                        }
                        tt << b;
                    }
               }
               if(BREAK)
                   break;
            }
        }
        //qDebug() << tt.join("");
        if(search_href->length()>1){
            search_title->insert(0,"My Bugs");
            if(search_href->length() == search_title->length()){
                for(int i=0;i<search_href->length();i++){
                    ui->comboBox->insertItem(i,search_title->at(i));
                }
            }
        }
    }
}


void Test::on_getbug_clicked()
{
    if(finish){
        finish = false;
        QNetworkRequest request(QUrl(TOP));
        QString in = "Bugzilla_login=%1&Bugzilla_password=%2&Bugzilla_restrictlogin=on&GoAheadAndLogIn=1&GoAheadAndLogIn=Log+in";
        in = in.arg(Config::getName()).arg(Config::getPWD());
        manager->post(request,in.toLatin1());
    }else{
        QMessageBox::information(this,"is loading...","Please wait");
        qDebug() << "wait";
    }
}

void Test::on_comboBox_activated(QString href)
{
    bugs->clear();
    ui->tableWidget->clear();
    int index = search_title->indexOf(href);
    QNetworkRequest request(QUrl(QString(TOP).append(search_href->at(index))));
    manager->get(request);
}

