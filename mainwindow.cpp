#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include <QByteArray>
#include <QDebug>

//#include <QGraphicsView>
//#include <QGraphicsScene>
//#include <QLabel>
//#include <QThread>
//#include "opt/an.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);
    setWindowTitle("MT");
    setFixedSize(600,400);
    QTabWidget *tabw = ui->tabWidget;
    Test *test = new Test(this);
    tabw->addTab(test,"test");
    tabw->resize(QSize(590,380));
    Tools *tools = new Tools(this);
    tabw->addTab(tools,"tools");
    git = new Git(this);
    tabw->addTab(git,"shell");
    Config *config = new Config(this);
    tabw->addTab(config,"config");
    connect(config,SIGNAL(config_change()),git,SLOT(config_change()));
//    QGraphicsScene *scene = new QGraphicsScene(this);
//    scene->addWidget(new QLabel());
//    QGraphicsView *view = new QGraphicsView(scene,this);
//    view->setGeometry(250,150,100,100);
//    An *an = new An();
//    an->set(view);
//    an->run();
    //view->rotate(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



void MainWindow::on_checkBox_clicked(bool checked)
{
    if(checked)
        setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    else
        setWindowFlags(Qt::Window);
    setFixedSize(600,400);
    show();
}
