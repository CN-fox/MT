/********************************************************************************
** Form generated from reading UI file 'pushcode.ui'
**
** Created: Sat Jun 21 18:30:59 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUSHCODE_H
#define UI_PUSHCODE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PushCode
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *bug_id;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *commit;
    QLabel *label_5;
    QLineEdit *suggestion;
    QPushButton *push;
    QLineEdit *solution;
    QLabel *label_6;
    QLabel *label_2;
    QLineEdit *report;
    QComboBox *root_cause;
    QPushButton *pushButton;

    void setupUi(QDialog *PushCode)
    {
        if (PushCode->objectName().isEmpty())
            PushCode->setObjectName(QString::fromUtf8("PushCode"));
        PushCode->resize(396, 297);
        gridLayout = new QGridLayout(PushCode);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(PushCode);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        bug_id = new QLineEdit(PushCode);
        bug_id->setObjectName(QString::fromUtf8("bug_id"));

        gridLayout->addWidget(bug_id, 0, 1, 1, 1);

        label_3 = new QLabel(PushCode);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(PushCode);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        commit = new QLineEdit(PushCode);
        commit->setObjectName(QString::fromUtf8("commit"));

        gridLayout->addWidget(commit, 3, 1, 1, 1);

        label_5 = new QLabel(PushCode);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        suggestion = new QLineEdit(PushCode);
        suggestion->setObjectName(QString::fromUtf8("suggestion"));

        gridLayout->addWidget(suggestion, 4, 1, 1, 1);

        push = new QPushButton(PushCode);
        push->setObjectName(QString::fromUtf8("push"));

        gridLayout->addWidget(push, 8, 1, 1, 1);

        solution = new QLineEdit(PushCode);
        solution->setObjectName(QString::fromUtf8("solution"));

        gridLayout->addWidget(solution, 5, 1, 1, 1);

        label_6 = new QLabel(PushCode);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_2 = new QLabel(PushCode);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        report = new QLineEdit(PushCode);
        report->setObjectName(QString::fromUtf8("report"));

        gridLayout->addWidget(report, 6, 1, 1, 1);

        root_cause = new QComboBox(PushCode);
        root_cause->setObjectName(QString::fromUtf8("root_cause"));

        gridLayout->addWidget(root_cause, 2, 1, 1, 1);

        pushButton = new QPushButton(PushCode);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 8, 0, 1, 1);


        retranslateUi(PushCode);

        QMetaObject::connectSlotsByName(PushCode);
    } // setupUi

    void retranslateUi(QDialog *PushCode)
    {
        PushCode->setWindowTitle(QApplication::translate("PushCode", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PushCode", "bug number:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PushCode", "root cause:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PushCode", "patch comments:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PushCode", "Test_Suggestion:", 0, QApplication::UnicodeUTF8));
        push->setText(QApplication::translate("PushCode", "PUSH", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PushCode", "Solution:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PushCode", "Test_Report:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("PushCode", "Default add All", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("PushCode", "Select File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PushCode: public Ui_PushCode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUSHCODE_H
