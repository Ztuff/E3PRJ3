/********************************************************************************
** Form generated from reading UI file 'fjernsensorkonf.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FJERNSENSORKONF_H
#define UI_FJERNSENSORKONF_H

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
            fjernsensorkonf->setObjectName(QString::fromUtf8("fjernsensorkonf"));
        fjernsensorkonf->resize(320, 240);
        SensorKonfigurationList = new QListWidget(fjernsensorkonf);
        SensorKonfigurationList->setObjectName(QString::fromUtf8("SensorKonfigurationList"));
        SensorKonfigurationList->setGeometry(QRect(10, 50, 291, 151));
        label_5 = new QLabel(fjernsensorkonf);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 20, 181, 20));
        backButton = new QPushButton(fjernsensorkonf);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(10, 10, 31, 23));
        saveButton = new QPushButton(fjernsensorkonf);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(250, 210, 61, 21));

        retranslateUi(fjernsensorkonf);

        QMetaObject::connectSlotsByName(fjernsensorkonf);
    } // setupUi

    void retranslateUi(QWidget *fjernsensorkonf)
    {
        fjernsensorkonf->setWindowTitle(QApplication::translate("fjernsensorkonf", "Form", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("fjernsensorkonf", "Slet Sensorkonfiguration", 0, QApplication::UnicodeUTF8));
        backButton->setText(QApplication::translate("fjernsensorkonf", "<", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("fjernsensorkonf", "Slet", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fjernsensorkonf: public Ui_fjernsensorkonf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FJERNSENSORKONF_H
