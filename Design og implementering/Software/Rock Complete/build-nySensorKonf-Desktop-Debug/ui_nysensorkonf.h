/********************************************************************************
** Form generated from reading UI file 'nysensorkonf.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NYSENSORKONF_H
#define UI_NYSENSORKONF_H

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

class Ui_NySensorKonf
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *MappingschemeDropdown;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *Sensordropdown;
    QComboBox *AkseDropdown;
    QPushButton *saveButton;
    QLineEdit *SensorName;
    QPushButton *backButton;
    QPushButton *NewMappingscheme;
    QComboBox *LydpakkeDropdown;

    void setupUi(QWidget *NySensorKonf)
    {
        if (NySensorKonf->objectName().isEmpty())
            NySensorKonf->setObjectName(QStringLiteral("NySensorKonf"));
        NySensorKonf->resize(480, 272);
        label = new QLabel(NySensorKonf);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 57, 15));
        label_2 = new QLabel(NySensorKonf);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 70, 111, 16));
        MappingschemeDropdown = new QComboBox(NySensorKonf);
        MappingschemeDropdown->setObjectName(QStringLiteral("MappingschemeDropdown"));
        MappingschemeDropdown->setGeometry(QRect(20, 150, 161, 21));
        label_3 = new QLabel(NySensorKonf);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 130, 121, 16));
        label_4 = new QLabel(NySensorKonf);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 130, 121, 16));
        label_5 = new QLabel(NySensorKonf);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 10, 161, 16));
        Sensordropdown = new QComboBox(NySensorKonf);
        Sensordropdown->setObjectName(QStringLiteral("Sensordropdown"));
        Sensordropdown->setGeometry(QRect(20, 92, 211, 21));
        AkseDropdown = new QComboBox(NySensorKonf);
        AkseDropdown->setObjectName(QStringLiteral("AkseDropdown"));
        AkseDropdown->setGeometry(QRect(240, 90, 211, 23));
        saveButton = new QPushButton(NySensorKonf);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(410, 240, 61, 23));
        SensorName = new QLineEdit(NySensorKonf);
        SensorName->setObjectName(QStringLiteral("SensorName"));
        SensorName->setGeometry(QRect(172, 40, 131, 23));
        backButton = new QPushButton(NySensorKonf);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 31, 23));
        NewMappingscheme = new QPushButton(NySensorKonf);
        NewMappingscheme->setObjectName(QStringLiteral("NewMappingscheme"));
        NewMappingscheme->setGeometry(QRect(190, 150, 41, 23));
        LydpakkeDropdown = new QComboBox(NySensorKonf);
        LydpakkeDropdown->setObjectName(QStringLiteral("LydpakkeDropdown"));
        LydpakkeDropdown->setGeometry(QRect(240, 150, 211, 23));

        retranslateUi(NySensorKonf);

        QMetaObject::connectSlotsByName(NySensorKonf);
    } // setupUi

    void retranslateUi(QWidget *NySensorKonf)
    {
        NySensorKonf->setWindowTitle(QApplication::translate("NySensorKonf", "Form", 0));
        label->setText(QApplication::translate("NySensorKonf", "Sensor", 0));
        label_2->setText(QApplication::translate("NySensorKonf", "Akse", 0));
        label_3->setText(QApplication::translate("NySensorKonf", "Mapping Scheme", 0));
        label_4->setText(QApplication::translate("NySensorKonf", "Lydpakke", 0));
        label_5->setText(QApplication::translate("NySensorKonf", "Ny Sensorkonfiguration", 0));
        saveButton->setText(QApplication::translate("NySensorKonf", "Gem", 0));
        SensorName->setText(QApplication::translate("NySensorKonf", "Indtast navn her", 0));
        backButton->setText(QApplication::translate("NySensorKonf", "<", 0));
        NewMappingscheme->setText(QApplication::translate("NySensorKonf", "New", 0));
    } // retranslateUi

};

namespace Ui {
    class NySensorKonf: public Ui_NySensorKonf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NYSENSORKONF_H