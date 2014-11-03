#include "pushcode.h"
#include "ui_pushcode.h"
#include <QDebug>
#include <QDir>
#include <QTextStream>

PushCode::PushCode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PushCode)
{
    ui->setupUi(this);
    git = (Git *)parent;
    init();
}

PushCode::~PushCode()
{
    delete ui;
}

void PushCode::init()
{
    setWindowTitle("Commit");
    QStringList items;
    items << "Unknown_Today" << "Architecture" << "Specification" << "Design" << "Coding" << "Regression" << "Evolution";
    ui->root_cause->addItems(items);
}

void PushCode::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PushCode::on_root_cause_activated(QString cause)
{
    this->cause = cause;
}

void PushCode::on_push_clicked()
{
    QString comment = ui->commit->text().trimmed();
    QString bug_number = ui->bug_id->text().trimmed();
    QString root_cause = ui->root_cause->currentText();
    QString suggestion = ui->suggestion->text().trimmed();
    QString solution = ui->solution->text().trimmed();
    QString report = ui->report->text().trimmed();
    QString product;
    QString module;

    QString commitName = QDir::homePath().append("/.MT/commit");
    QFile *tmpFile = new QFile(commitName);
    tmpFile->open(QFile::WriteOnly|QFile::Truncate);
    QTextStream out(tmpFile);
    QStringList commit_list;
    commit_list << QString("###%%%comment:%1").arg(comment);
    commit_list << QString("###%%%bug number:%1").arg(bug_number);
    commit_list << QString("###%%%product name:%1").arg(git->products.at(0));
    commit_list << QString("###%%%root cause:%1").arg(root_cause);
    commit_list << QString("###%%%Module_Impact:%1").arg(git->module_name);
    commit_list << QString("###%%%Test_Suggestion:%1").arg(suggestion);
    commit_list << QString("###%%%Solution:%1").arg(solution);
    commit_list << QString("###%%%Test_Report:%1").arg(report);
    out << commit_list.join("\n");
    out.flush();
    QLinkedList<QString> *task = git->getTask();
    task->append(QString("git status"));
    task->append(QString("git add --all"));
    task->append(QString("git commit -F ").append(commitName));
    git->command(task);
    this->close();
}
