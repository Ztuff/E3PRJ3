/********************************************************************************
** Form generated from reading UI file 'redigersenskonf.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDIGERSENSKONF_H
#define UI_REDIGERSENSKONF_H

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

class Ui_redigersenskonf
{
public:
    QListWidget *SensorKonfigurationList;
    QLabel *label_5;
    QPushButton *backButton;
    QPushButton *saveButton;

    void setupUi(QWidget *redigersenskonf)
    {
        if (redigersenskonf->objectName().isEmpty())
            redigersenskonf->setObjectName(QStringLiteral("redigersenskonf"));
        redigersenskonf->resize(497, 292);
        SensorKonfigurationList = new QListWidget(redigersenskonf);
        SensorKonfigurationList->setObjectName(QStringLiteral("SensorKonfigurationList"));
        SensorKonfigurationList->setGeometry(QRect(30, 40, 431, 192));
        label_5 = new QLabel(redigersenskonf);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 10, 181, 20));
        backButton = new QPushButton(redigersenskonf);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 31, 23));
        saveButton = new QPushButton(redigersenskonf);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(400, 240, 61, 21));

        retranslateUi(redigersenskonf);

        QMetaObject::connectSlotsByName(redigersenskonf);
    } // setupUi

    void retranslateUi(QWidget *redigersenskonf)
    {
        redigersenskonf->setWindowTitle(QApplication::translate("redigersenskonf", "Redig\303\251r Sensorkonfiguration", 0));
        label_5->setText(QApplication::translate("redigersenskonf", "Redig\303\251r Sensorkonfiguration", 0));
        backButton->setText(QApplication::translate("redigersenskonf", "<", 0));
        saveButton->setText(QApplication::translate("redigersenskonf", "V\303\246lg", 0));
    } // retranslateUi

};

namespace Ui {
    class redigersenskonf: public Ui_redigersenskonf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDIGERSENSKONF_H
