#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sensorwindow.h"

MainWindow::MainWindow(QWidget *parent, MsgHandler *msg) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    msgH_ = msg;
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Sensorer_clicked()
{
    QWidget* parent = 0;
    SensorWindow *sWindow = new SensorWindow(parent, msgH_);
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
