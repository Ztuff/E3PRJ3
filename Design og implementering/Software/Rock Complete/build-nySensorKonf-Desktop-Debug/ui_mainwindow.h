/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Sensorer;
    QPushButton *Lydpakker;
    QPushButton *Presets;
    QLabel *label;
    QPushButton *CloseButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(480, 272);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 60, 481, 151));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(10, 0, 10, 0);
        Sensorer = new QPushButton(gridLayoutWidget);
        Sensorer->setObjectName(QStringLiteral("Sensorer"));
        Sensorer->setMinimumSize(QSize(0, 60));

        gridLayout->addWidget(Sensorer, 0, 0, 1, 1);

        Lydpakker = new QPushButton(gridLayoutWidget);
        Lydpakker->setObjectName(QStringLiteral("Lydpakker"));
        Lydpakker->setMinimumSize(QSize(0, 60));

        gridLayout->addWidget(Lydpakker, 0, 1, 1, 1);

        Presets = new QPushButton(gridLayoutWidget);
        Presets->setObjectName(QStringLiteral("Presets"));
        Presets->setMinimumSize(QSize(0, 60));

        gridLayout->addWidget(Presets, 0, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 10, 101, 16));
        CloseButton = new QPushButton(centralWidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(10, 10, 31, 23));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Sensorer->setText(QApplication::translate("MainWindow", "Sensorer", 0));
        Lydpakker->setText(QApplication::translate("MainWindow", "Lydpakker", 0));
        Presets->setText(QApplication::translate("MainWindow", "Presets", 0));
        label->setText(QApplication::translate("MainWindow", "BodyRock 3000", 0));
        CloseButton->setText(QApplication::translate("MainWindow", "X", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
