#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "config.h"
#include "tools.h"
#include "git.h"
#include "test.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static QString product_path ;
    static QString sdk_path;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    Git *git;


private slots:
    void on_checkBox_clicked(bool checked);
};

#endif // MAINWINDOW_H
