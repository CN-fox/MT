/********************************************************************************
** Form generated from reading UI file 'git.ui'
**
** Created: Sat Jun 21 18:30:59 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIT_H
#define UI_GIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Git
{
public:
    QGroupBox *groupBox;
    QTextEdit *textEdit;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *product_name;
    QPushButton *search;
    QComboBox *select;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QPushButton *diff;
    QPushButton *push_apk;
    QPushButton *push_code;
    QPushButton *tcpdump;
    QPushButton *push_rom;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *command_text;
    QPushButton *run;
    QPushButton *make;

    void setupUi(QWidget *Git)
    {
        if (Git->objectName().isEmpty())
            Git->setObjectName(QString::fromUtf8("Git"));
        Git->resize(590, 340);
        groupBox = new QGroupBox(Git);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 180, 551, 141));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 531, 111));
        textEdit->setReadOnly(true);
        layoutWidget = new QWidget(Git);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 541, 41));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        product_name = new QLineEdit(layoutWidget);
        product_name->setObjectName(QString::fromUtf8("product_name"));
        product_name->setEchoMode(QLineEdit::Normal);

        gridLayout->addWidget(product_name, 0, 0, 1, 1);

        search = new QPushButton(layoutWidget);
        search->setObjectName(QString::fromUtf8("search"));
        search->setMinimumSize(QSize(24, 24));
        search->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/search.svg);"));
        search->setIconSize(QSize(28, 28));

        gridLayout->addWidget(search, 0, 1, 1, 1);

        select = new QComboBox(layoutWidget);
        select->setObjectName(QString::fromUtf8("select"));
        select->setMinimumSize(QSize(250, 0));
        select->setModelColumn(0);

        gridLayout->addWidget(select, 0, 2, 1, 1);

        layoutWidget1 = new QWidget(Git);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 60, 541, 41));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        diff = new QPushButton(layoutWidget1);
        diff->setObjectName(QString::fromUtf8("diff"));

        gridLayout_2->addWidget(diff, 0, 0, 1, 1);

        push_apk = new QPushButton(layoutWidget1);
        push_apk->setObjectName(QString::fromUtf8("push_apk"));

        gridLayout_2->addWidget(push_apk, 0, 1, 1, 1);

        push_code = new QPushButton(layoutWidget1);
        push_code->setObjectName(QString::fromUtf8("push_code"));

        gridLayout_2->addWidget(push_code, 0, 2, 1, 1);

        tcpdump = new QPushButton(layoutWidget1);
        tcpdump->setObjectName(QString::fromUtf8("tcpdump"));

        gridLayout_2->addWidget(tcpdump, 0, 4, 1, 1);

        push_rom = new QPushButton(layoutWidget1);
        push_rom->setObjectName(QString::fromUtf8("push_rom"));

        gridLayout_2->addWidget(push_rom, 0, 3, 1, 1);

        layoutWidget2 = new QWidget(Git);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 110, 411, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        command_text = new QLineEdit(layoutWidget2);
        command_text->setObjectName(QString::fromUtf8("command_text"));

        horizontalLayout->addWidget(command_text);

        run = new QPushButton(layoutWidget2);
        run->setObjectName(QString::fromUtf8("run"));

        horizontalLayout->addWidget(run);

        make = new QPushButton(Git);
        make->setObjectName(QString::fromUtf8("make"));
        make->setGeometry(QRect(450, 110, 93, 27));

        retranslateUi(Git);

        QMetaObject::connectSlotsByName(Git);
    } // setupUi

    void retranslateUi(QWidget *Git)
    {
        Git->setWindowTitle(QApplication::translate("Git", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Git", "Out", 0, QApplication::UnicodeUTF8));
        search->setText(QString());
        diff->setText(QApplication::translate("Git", "diff", 0, QApplication::UnicodeUTF8));
        push_apk->setText(QApplication::translate("Git", "push apk", 0, QApplication::UnicodeUTF8));
        push_code->setText(QApplication::translate("Git", "push code", 0, QApplication::UnicodeUTF8));
        tcpdump->setText(QApplication::translate("Git", "tcpdump", 0, QApplication::UnicodeUTF8));
        push_rom->setText(QApplication::translate("Git", "push rom", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Git", "Command:", 0, QApplication::UnicodeUTF8));
        run->setText(QApplication::translate("Git", "Run", 0, QApplication::UnicodeUTF8));
        make->setText(QApplication::translate("Git", "make", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Git: public Ui_Git {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIT_H
