/********************************************************************************
** Form generated from reading UI file 'redigersenskonf2.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDIGERSENSKONF2_H
#define UI_REDIGERSENSKONF2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_redigersenskonf2
{
public:
    QPushButton *NewMappingscheme;
    QLabel *label;
    QLabel *label_2;
    QComboBox *Sensordropdown;
    QComboBox *MappingschemeDropdown;
    QComboBox *LydpakkeDropdown;
    QPushButton *saveButton;
    QLabel *label_4;
    QLineEdit *SensorName;
    QPushButton *backButton;
    QComboBox *AkseDropdown;
    QLabel *label_3;
    QLabel *label_5;

    void setupUi(QWidget *redigersenskonf2)
    {
        if (redigersenskonf2->objectName().isEmpty())
            redigersenskonf2->setObjectName(QStringLiteral("redigersenskonf2"));
        redigersenskonf2->resize(509, 300);
        NewMappingscheme = new QPushButton(redigersenskonf2);
        NewMappingscheme->setObjectName(QStringLiteral("NewMappingscheme"));
        NewMappingscheme->setGeometry(QRect(190, 150, 41, 23));
        label = new QLabel(redigersenskonf2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 57, 15));
        label_2 = new QLabel(redigersenskonf2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 70, 111, 16));
        Sensordropdown = new QComboBox(redigersenskonf2);
        Sensordropdown->setObjectName(QStringLiteral("Sensordropdown"));
        Sensordropdown->setGeometry(QRect(20, 92, 211, 21));
        MappingschemeDropdown = new QComboBox(redigersenskonf2);
        MappingschemeDropdown->setObjectName(QStringLiteral("MappingschemeDropdown"));
        MappingschemeDropdown->setGeometry(QRect(20, 150, 161, 21));
        LydpakkeDropdown = new QComboBox(redigersenskonf2);
        LydpakkeDropdown->setObjectName(QStringLiteral("LydpakkeDropdown"));
        LydpakkeDropdown->setGeometry(QRect(240, 150, 211, 23));
        saveButton = new QPushButton(redigersenskonf2);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(410, 240, 61, 23));
        label_4 = new QLabel(redigersenskonf2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 130, 121, 16));
        SensorName = new QLineEdit(redigersenskonf2);
        SensorName->setObjectName(QStringLiteral("SensorName"));
        SensorName->setGeometry(QRect(172, 40, 131, 23));
        SensorName->setReadOnly(true);
        backButton = new QPushButton(redigersenskonf2);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 31, 23));
        AkseDropdown = new QComboBox(redigersenskonf2);
        AkseDropdown->setObjectName(QStringLiteral("AkseDropdown"));
        AkseDropdown->setGeometry(QRect(240, 90, 211, 23));
        label_3 = new QLabel(redigersenskonf2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 130, 121, 16));
        label_5 = new QLabel(redigersenskonf2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 10, 191, 16));

        retranslateUi(redigersenskonf2);

        QMetaObject::connectSlotsByName(redigersenskonf2);
    } // setupUi

    void retranslateUi(QWidget *redigersenskonf2)
    {
        redigersenskonf2->setWindowTitle(QApplication::translate("redigersenskonf2", "Form", 0));
        NewMappingscheme->setText(QApplication::translate("redigersenskonf2", "New", 0));
        label->setText(QApplication::translate("redigersenskonf2", "Sensor", 0));
        label_2->setText(QApplication::translate("redigersenskonf2", "Akse", 0));
        saveButton->setText(QApplication::translate("redigersenskonf2", "Gem", 0));
        label_4->setText(QApplication::translate("redigersenskonf2", "Lydpakke", 0));
        SensorName->setText(QApplication::translate("redigersenskonf2", "Indtast navn her", 0));
        backButton->setText(QApplication::translate("redigersenskonf2", "<", 0));
        label_3->setText(QApplication::translate("redigersenskonf2", "Mapping Scheme", 0));
        label_5->setText(QApplication::translate("redigersenskonf2", "Redig\303\251r Sensorkonfiguration", 0));
    } // retranslateUi

};

namespace Ui {
    class redigersenskonf2: public Ui_redigersenskonf2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDIGERSENSKONF2_H
