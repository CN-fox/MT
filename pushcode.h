#ifndef PUSHCODE_H
#define PUSHCODE_H

#include <QDialog>
#include "git.h"

namespace Ui {
    class PushCode;
}

class PushCode : public QDialog {
    Q_OBJECT
public:
    PushCode(QWidget *parent = 0);
    ~PushCode();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::PushCode *ui;
    QString cause;
    void init();
    Git *git;

private slots:
    void on_push_clicked();
    void on_root_cause_activated(QString );
};

#endif // PUSHCODE_H
