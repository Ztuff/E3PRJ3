/********************************************************************************
** Form generated from reading UI file 'redigersensorkonf.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDIGERSENSORKONF_H
#define UI_REDIGERSENSORKONF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *saveButton;
    QPushButton *backButton;
    QLabel *label_5;
    QListWidget *SensorKonfigurationList;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(494, 300);
        saveButton = new QPushButton(Form);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(400, 240, 61, 21));
        backButton = new QPushButton(Form);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 31, 23));
        label_5 = new QLabel(Form);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 10, 181, 20));
        SensorKonfigurationList = new QListWidget(Form);
        SensorKonfigurationList->setObjectName(QStringLiteral("SensorKonfigurationList"));
        SensorKonfigurationList->setGeometry(QRect(30, 40, 431, 192));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        saveButton->setText(QApplication::translate("Form", "V\303\246lg", 0));
        backButton->setText(QApplication::translate("Form", "<", 0));
        label_5->setText(QApplication::translate("Form", "Redig\303\251r Sensorkonfiguration", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDIGERSENSORKONF_H
