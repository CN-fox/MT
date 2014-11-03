/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created: Sat Jun 21 18:30:59 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QPushButton *getbug;
    QTableWidget *tableWidget;
    QComboBox *comboBox;

    void setupUi(QWidget *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName(QString::fromUtf8("Test"));
        Test->resize(590, 340);
        getbug = new QPushButton(Test);
        getbug->setObjectName(QString::fromUtf8("getbug"));
        getbug->setGeometry(QRect(80, 10, 25, 25));
        getbug->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/view-refresh.svg);"));
        tableWidget = new QTableWidget(Test);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 60, 551, 261));
        comboBox = new QComboBox(Test);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 10, 181, 27));

        retranslateUi(Test);

        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QWidget *Test)
    {
        Test->setWindowTitle(QApplication::translate("Test", "Form", 0, QApplication::UnicodeUTF8));
        getbug->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
