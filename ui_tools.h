/********************************************************************************
** Form generated from reading UI file 'tools.ui'
**
** Created: Sat Jun 21 18:30:59 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLS_H
#define UI_TOOLS_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tools
{
public:
    QPushButton *pushButton;
    QPushButton *ddms;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *note_1;
    QPushButton *cp1;
    QLineEdit *note_2;
    QPushButton *cp2;
    QHBoxLayout *HLayout;
    QLabel *label;
    QLineEdit *bug_id;
    QLabel *label_2;
    QLineEdit *des;
    QComboBox *issue;
    QLineEdit *note_3;
    QPushButton *cp3;

    void setupUi(QWidget *Tools)
    {
        if (Tools->objectName().isEmpty())
            Tools->setObjectName(QString::fromUtf8("Tools"));
        Tools->resize(590, 340);
        pushButton = new QPushButton(Tools);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 120, 27));
        pushButton->setMaximumSize(QSize(150, 100));
        ddms = new QPushButton(Tools);
        ddms->setObjectName(QString::fromUtf8("ddms"));
        ddms->setGeometry(QRect(150, 10, 85, 27));
        ddms->setMaximumSize(QSize(100, 100));
        groupBox = new QGroupBox(Tools);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 541, 151));
        groupBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        note_1 = new QLineEdit(groupBox);
        note_1->setObjectName(QString::fromUtf8("note_1"));
        note_1->setDragEnabled(false);
        note_1->setReadOnly(true);

        gridLayout->addWidget(note_1, 2, 0, 1, 1);

        cp1 = new QPushButton(groupBox);
        cp1->setObjectName(QString::fromUtf8("cp1"));

        gridLayout->addWidget(cp1, 2, 1, 1, 1);

        note_2 = new QLineEdit(groupBox);
        note_2->setObjectName(QString::fromUtf8("note_2"));
        note_2->setReadOnly(true);

        gridLayout->addWidget(note_2, 4, 0, 1, 1);

        cp2 = new QPushButton(groupBox);
        cp2->setObjectName(QString::fromUtf8("cp2"));

        gridLayout->addWidget(cp2, 4, 1, 1, 1);

        HLayout = new QHBoxLayout();
        HLayout->setObjectName(QString::fromUtf8("HLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        HLayout->addWidget(label);

        bug_id = new QLineEdit(groupBox);
        bug_id->setObjectName(QString::fromUtf8("bug_id"));
        bug_id->setMinimumSize(QSize(0, 22));

        HLayout->addWidget(bug_id);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        HLayout->addWidget(label_2);

        des = new QLineEdit(groupBox);
        des->setObjectName(QString::fromUtf8("des"));
        des->setMinimumSize(QSize(0, 22));

        HLayout->addWidget(des);


        gridLayout->addLayout(HLayout, 0, 0, 1, 1);

        issue = new QComboBox(groupBox);
        issue->setObjectName(QString::fromUtf8("issue"));
        issue->setEditable(false);

        gridLayout->addWidget(issue, 0, 1, 1, 1);

        note_3 = new QLineEdit(groupBox);
        note_3->setObjectName(QString::fromUtf8("note_3"));
        note_3->setReadOnly(true);

        gridLayout->addWidget(note_3, 5, 0, 1, 1);

        cp3 = new QPushButton(groupBox);
        cp3->setObjectName(QString::fromUtf8("cp3"));

        gridLayout->addWidget(cp3, 5, 1, 1, 1);


        retranslateUi(Tools);

        QMetaObject::connectSlotsByName(Tools);
    } // setupUi

    void retranslateUi(QWidget *Tools)
    {
        Tools->setWindowTitle(QApplication::translate("Tools", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Tools", "hierarchyviewer", 0, QApplication::UnicodeUTF8));
        ddms->setText(QApplication::translate("Tools", "ddms", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Tools", "Annotation", 0, QApplication::UnicodeUTF8));
        note_1->setText(QString());
        cp1->setText(QApplication::translate("Tools", "copy", 0, QApplication::UnicodeUTF8));
        note_2->setText(QString());
        cp2->setText(QApplication::translate("Tools", "copy", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Tools", "Bug ID:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Tools", "Des:", 0, QApplication::UnicodeUTF8));
        note_3->setText(QString());
        cp3->setText(QApplication::translate("Tools", "copy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Tools: public Ui_Tools {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLS_H
