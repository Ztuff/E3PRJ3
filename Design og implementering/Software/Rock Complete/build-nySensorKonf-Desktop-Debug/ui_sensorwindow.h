/********************************************************************************
** Form generated from reading UI file 'sensorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSORWINDOW_H
#define UI_SENSORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SensorWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *RedigerSensorKon;
    QPushButton *NySensorkon;
    QPushButton *SletSensorKon;
    QLabel *label;
    QPushButton *backButton;

    void setupUi(QWidget *SensorWindow)
    {
        if (SensorWindow->objectName().isEmpty())
            SensorWindow->setObjectName(QStringLiteral("SensorWindow"));
        SensorWindow->resize(480, 272);
        SensorWindow->setMinimumSize(QSize(480, 272));
        gridLayoutWidget = new QWidget(SensorWindow);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 70, 481, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setContentsMargins(10, 0, 10, 0);
        RedigerSensorKon = new QPushButton(gridLayoutWidget);
        RedigerSensorKon->setObjectName(QStringLiteral("RedigerSensorKon"));
        RedigerSensorKon->setMinimumSize(QSize(0, 60));
        RedigerSensorKon->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(RedigerSensorKon, 0, 1, 1, 1);

        NySensorkon = new QPushButton(gridLayoutWidget);
        NySensorkon->setObjectName(QStringLiteral("NySensorkon"));
        NySensorkon->setMinimumSize(QSize(0, 60));
        NySensorkon->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(NySensorkon, 0, 0, 1, 1);

        SletSensorKon = new QPushButton(gridLayoutWidget);
        SletSensorKon->setObjectName(QStringLiteral("SletSensorKon"));
        SletSensorKon->setMinimumSize(QSize(0, 60));
        SletSensorKon->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(SletSensorKon, 0, 2, 1, 1);

        label = new QLabel(SensorWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 10, 151, 16));
        backButton = new QPushButton(SensorWindow);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 10, 31, 23));

        retranslateUi(SensorWindow);

        QMetaObject::connectSlotsByName(SensorWindow);
    } // setupUi

    void retranslateUi(QWidget *SensorWindow)
    {
        SensorWindow->setWindowTitle(QApplication::translate("SensorWindow", "Form", 0));
        RedigerSensorKon->setText(QApplication::translate("SensorWindow", "Rediger \n"
"Sensorkonfiguration", 0));
        NySensorkon->setText(QApplication::translate("SensorWindow", "Ny \n"
"Sensorkonfiguration", 0));
        SletSensorKon->setText(QApplication::translate("SensorWindow", "Slet \n"
"Sensorkonfiguration", 0));
        label->setText(QApplication::translate("SensorWindow", "Sensorkonfigurationer", 0));
        backButton->setText(QApplication::translate("SensorWindow", "<", 0));
    } // retranslateUi

};

namespace Ui {
    class SensorWindow: public Ui_SensorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSORWINDOW_H
