/********************************************************************************
** Form generated from reading UI file 'redigersenskonf2.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDIGERSENSKONF2_H
#define UI_REDIGERSENSKONF2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

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
            redigersenskonf2->setObjectName(QString::fromUtf8("redigersenskonf2"));
        redigersenskonf2->resize(320, 240);
        NewMappingscheme = new QPushButton(redigersenskonf2);
        NewMappingscheme->setObjectName(QString::fromUtf8("NewMappingscheme"));
        NewMappingscheme->setGeometry(QRect(130, 150, 41, 23));
        label = new QLabel(redigersenskonf2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 70, 57, 15));
        label_2 = new QLabel(redigersenskonf2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 70, 111, 16));
        Sensordropdown = new QComboBox(redigersenskonf2);
        Sensordropdown->setObjectName(QString::fromUtf8("Sensordropdown"));
        Sensordropdown->setGeometry(QRect(10, 90, 141, 21));
        MappingschemeDropdown = new QComboBox(redigersenskonf2);
        MappingschemeDropdown->setObjectName(QString::fromUtf8("MappingschemeDropdown"));
        MappingschemeDropdown->setGeometry(QRect(10, 150, 111, 21));
        LydpakkeDropdown = new QComboBox(redigersenskonf2);
        LydpakkeDropdown->setObjectName(QString::fromUtf8("LydpakkeDropdown"));
        LydpakkeDropdown->setGeometry(QRect(180, 150, 131, 23));
        saveButton = new QPushButton(redigersenskonf2);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(240, 200, 61, 23));
        label_4 = new QLabel(redigersenskonf2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 130, 121, 16));
        SensorName = new QLineEdit(redigersenskonf2);
        SensorName->setObjectName(QString::fromUtf8("SensorName"));
        SensorName->setGeometry(QRect(110, 40, 131, 23));
        SensorName->setReadOnly(true);
        backButton = new QPushButton(redigersenskonf2);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(10, 10, 31, 23));
        AkseDropdown = new QComboBox(redigersenskonf2);
        AkseDropdown->setObjectName(QString::fromUtf8("AkseDropdown"));
        AkseDropdown->setGeometry(QRect(170, 90, 141, 23));
        label_3 = new QLabel(redigersenskonf2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 130, 121, 16));
        label_5 = new QLabel(redigersenskonf2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 10, 191, 16));

        retranslateUi(redigersenskonf2);

        QMetaObject::connectSlotsByName(redigersenskonf2);
    } // setupUi

    void retranslateUi(QWidget *redigersenskonf2)
    {
        redigersenskonf2->setWindowTitle(QApplication::translate("redigersenskonf2", "Form", 0, QApplication::UnicodeUTF8));
        NewMappingscheme->setText(QApplication::translate("redigersenskonf2", "New", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("redigersenskonf2", "Sensor", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("redigersenskonf2", "Akse", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("redigersenskonf2", "Gem", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("redigersenskonf2", "Lydpakke", 0, QApplication::UnicodeUTF8));
        SensorName->setText(QApplication::translate("redigersenskonf2", "Indtast navn her", 0, QApplication::UnicodeUTF8));
        backButton->setText(QApplication::translate("redigersenskonf2", "<", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("redigersenskonf2", "Mapping Scheme", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("redigersenskonf2", "Redig\303\251r Sensorkonfiguration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class redigersenskonf2: public Ui_redigersenskonf2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDIGERSENSKONF2_H
