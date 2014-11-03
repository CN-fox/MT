/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created: Sat Jun 21 18:30:59 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QDialogButtonBox *save;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *product_path;
    QPushButton *product_select;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *name;
    QLabel *label_3;
    QLineEdit *email;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *sdk_path;
    QPushButton *sdk_select;

    void setupUi(QWidget *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QString::fromUtf8("Config"));
        Config->resize(590, 340);
        save = new QDialogButtonBox(Config);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(400, 290, 176, 27));
        save->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(Config);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 561, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        product_path = new QLineEdit(layoutWidget);
        product_path->setObjectName(QString::fromUtf8("product_path"));

        horizontalLayout->addWidget(product_path);

        product_select = new QPushButton(layoutWidget);
        product_select->setObjectName(QString::fromUtf8("product_select"));

        horizontalLayout->addWidget(product_select);

        layoutWidget1 = new QWidget(Config);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 561, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        name = new QLineEdit(layoutWidget1);
        name->setObjectName(QString::fromUtf8("name"));

        horizontalLayout_2->addWidget(name);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        email = new QLineEdit(layoutWidget1);
        email->setObjectName(QString::fromUtf8("email"));

        horizontalLayout_2->addWidget(email);

        layoutWidget2 = new QWidget(Config);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 100, 561, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        sdk_path = new QLineEdit(layoutWidget2);
        sdk_path->setObjectName(QString::fromUtf8("sdk_path"));

        horizontalLayout_3->addWidget(sdk_path);

        sdk_select = new QPushButton(layoutWidget2);
        sdk_select->setObjectName(QString::fromUtf8("sdk_select"));

        horizontalLayout_3->addWidget(sdk_select);


        retranslateUi(Config);

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QWidget *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Config", "Product:", 0, QApplication::UnicodeUTF8));
        product_select->setText(QApplication::translate("Config", "Select", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Config", "Name  : ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Config", "Email: ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Config", "android sdk:", 0, QApplication::UnicodeUTF8));
        sdk_select->setText(QApplication::translate("Config", "Select", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
