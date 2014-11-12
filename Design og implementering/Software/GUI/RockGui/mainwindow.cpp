#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sensorwindow.h"
#include "presetwindow.h"
#include "lydpakkerwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QtCore>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_PushButton_1_clicked()
{
    SensorWindow *sWindow = new SensorWindow;
    sWindow->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    PresetWindow *pWindow = new PresetWindow;
    pWindow->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    LydpakkerWindow *lWindow = new LydpakkerWindow;
    lWindow->show();
}

void MainWindow::on_CloseButton_clicked()
{
    this->close();
}
