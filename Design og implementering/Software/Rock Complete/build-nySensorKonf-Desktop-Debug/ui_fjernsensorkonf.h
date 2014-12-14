/********************************************************************************
** Form generated from reading UI file 'fjernsensorkonf.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FJERNSENSORKONF_H
#define UI_FJERNSENSORKONF_H

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

class Ui_fjernsensorkonf
{
public:
    QListWidget *SensorKonfigurationList;
    QLabel *label_5;
    QPushButton *backButton;
    QPushButton *saveButton;

    void setupUi(QWidget *fjernsensorkonf)
    {
        if (fjernsensorkonf->objectName().isEmpty())
            fjernsensorkonf->setObjectName(QStringLiteral("fjernsensorkonf"));
        fjernsensorkonf->resize(523, 330);
        SensorKonfigurationList = new QListWidget(fjernsensorkonf);
        SensorKonfigurationList->setObjectName(QStringLiteral("SensorKonfigurationList"));
        SensorKonfigurationList->setGeometry(QRect(40, 50, 431, 192));
        label_5 = new QLabel(fjernsensorkonf);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 20, 181, 20));
        backButton = new QPushButton(fjernsensorkonf);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 31, 23));
        saveButton = new QPushButton(fjernsensorkonf);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(410, 250, 61, 21));

        retranslateUi(fjernsensorkonf);

        QMetaObject::connectSlotsByName(fjernsensorkonf);
    } // setupUi

    void retranslateUi(QWidget *fjernsensorkonf)
    {
        fjernsensorkonf->setWindowTitle(QApplication::translate("fjernsensorkonf", "Form", 0));
        label_5->setText(QApplication::translate("fjernsensorkonf", "Slet Sensorkonfiguration", 0));
        backButton->setText(QApplication::translate("fjernsensorkonf", "<", 0));
        saveButton->setText(QApplication::translate("fjernsensorkonf", "Slet", 0));
    } // retranslateUi

};

namespace Ui {
    class fjernsensorkonf: public Ui_fjernsensorkonf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FJERNSENSORKONF_H
