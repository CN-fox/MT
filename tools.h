#ifndef TOOLS_H
#define TOOLS_H

#include <QWidget>

#define END "/* ----------|----------------------|----------------------|----------------- */"
#define MID "/*           |                      |                      |"

namespace Ui {
    class Tools;
}

class Tools : public QWidget {
    Q_OBJECT
public:
    Tools(QWidget *parent = 0);
    ~Tools();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Tools *ui;
    QString addSpace(int,QString);

private slots:
    void on_cp3_clicked();
    void on_issue_activated(QString );
    void on_cp2_clicked();
    void on_cp1_clicked();
    void on_ddms_clicked();
    void on_pushButton_clicked();
};

#endif // TOOLS_H
