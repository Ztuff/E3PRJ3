/********************************************************************************
** Form generated from reading UI file 'redigersenskonf.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDIGERSENSKONF_H
#define UI_REDIGERSENSKONF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

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
            redigersenskonf->setObjectName(QString::fromUtf8("redigersenskonf"));
        redigersenskonf->resize(320, 240);
        SensorKonfigurationList = new QListWidget(redigersenskonf);
        SensorKonfigurationList->setObjectName(QString::fromUtf8("SensorKonfigurationList"));
        SensorKonfigurationList->setGeometry(QRect(20, 40, 281, 161));
        label_5 = new QLabel(redigersenskonf);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 10, 181, 20));
        backButton = new QPushButton(redigersenskonf);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(10, 10, 31, 23));
        saveButton = new QPushButton(redigersenskonf);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(250, 210, 61, 21));

        retranslateUi(redigersenskonf);

        QMetaObject::connectSlotsByName(redigersenskonf);
    } // setupUi

    void retranslateUi(QWidget *redigersenskonf)
    {
        redigersenskonf->setWindowTitle(QApplication::translate("redigersenskonf", "Redig\303\251r Sensorkonfiguration", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("redigersenskonf", "Redig\303\251r Sensorkonfiguration", 0, QApplication::UnicodeUTF8));
        backButton->setText(QApplication::translate("redigersenskonf", "<", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("redigersenskonf", "V\303\246lg", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class redigersenskonf: public Ui_redigersenskonf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDIGERSENSKONF_H
