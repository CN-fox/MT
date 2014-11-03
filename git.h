#ifndef GIT_H
#define GIT_H

#include <QWidget>
#include <QProcess>
#include <QDomDocument>
#include <QMap>
#include <QLinkedList>
#include <QKeyEvent>

#define APP "/system/app/"
#define VENDOR "/system/vendor/"
#define PRIV "/system/priv-app/"
#define WITHOUTLIBS "/custpack/app/withoutlibs/"
#define OUT "/out/target/product/"
#define CUSTPACK "/custpack/JRD_custres/app/"
#define CUSTPACK_F "custpack/framework"
#define LOCAL_PACKAGE_NAME "LOCAL_PACKAGE_NAME"

namespace Ui {
    class Git;
}

struct moduleProduct{
    QString type;
    QString name;
};

class Git : public QWidget {
    Q_OBJECT
public:
    Git(QWidget *parent = 0);
    ~Git();
    void init();
    void command(QString);
    void command(QLinkedList<QString> *,bool print = true);
    void updateText(QString);
    QLinkedList<QString> * getTask();
    QString productName;
    QString module_name;
    QStringList products;

protected:
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *);

private:
    Ui::Git *ui;
    QProcess * process;
    QDomDocument doc;
    QMap<QString,QString> map;
    QString module;
    QLinkedList<QString> *task;
    bool pushApk(const QString);
    QList<moduleProduct> getModuleName();
    QList<moduleProduct> mP;
public slots:
    void config_change();
private slots:
    void on_run_clicked();
    void on_push_code_clicked();
    void on_make_clicked();
    void on_push_rom_clicked();
    void on_tcpdump_clicked();
    void on_push_apk_clicked();
    void on_diff_clicked();
    void on_select_activated(QString );
    void on_search_clicked();
    void read();
    void finished(int);

};

#endif // GIT_H
