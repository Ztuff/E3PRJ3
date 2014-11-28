#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sensorwindow.h"

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



void MainWindow::on_Sensorer_clicked()
{
    SensorWindow *sWindow = new SensorWindow;
    sWindow->show();
}

void MainWindow::on_Lydpakker_clicked()
{

}

void MainWindow::on_Presets_clicked()
{

}

void MainWindow::on_CloseButton_clicked()
{
    this->close();
}
