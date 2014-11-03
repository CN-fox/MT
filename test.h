#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QList>
#include "vo/bug.h"

#define TOP "http://bugzilla.tcl-ta.com/"
namespace Ui {
    class Test;
}

class Test : public QWidget {
    Q_OBJECT
public:
    Test(QWidget *parent = 0);
    ~Test();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Test *ui;
    QNetworkAccessManager *manager;
    QList<QString> *search_title;
    QList<QString> *search_href;
    QList<Bug*> *bugs;


private slots:
    void on_comboBox_activated(QString );
    void on_getbug_clicked();
    void finished(QNetworkReply*);
};

#endif // TEST_H
