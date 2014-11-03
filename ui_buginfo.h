/********************************************************************************
** Form generated from reading UI file 'buginfo.ui'
**
** Created: Wed Jun 25 15:39:07 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUGINFO_H
#define UI_BUGINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BugInfo
{
public:
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *BugInfo)
    {
        if (BugInfo->objectName().isEmpty())
            BugInfo->setObjectName(QString::fromUtf8("BugInfo"));
        BugInfo->resize(400, 300);
        label = new QLabel(BugInfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 62, 17));
        comboBox = new QComboBox(BugInfo);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 0, 85, 27));

        retranslateUi(BugInfo);

        QMetaObject::connectSlotsByName(BugInfo);
    } // setupUi

    void retranslateUi(QWidget *BugInfo)
    {
        BugInfo->setWindowTitle(QApplication::translate("BugInfo", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BugInfo", "Bug id:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BugInfo: public Ui_BugInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUGINFO_H
