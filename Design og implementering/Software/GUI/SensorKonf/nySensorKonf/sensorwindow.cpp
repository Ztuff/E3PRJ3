#include "sensorwindow.h"
#include "ui_sensorwindow.h"
#include "nysensorkonf.h"

SensorWindow::SensorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SensorWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

SensorWindow::~SensorWindow()
{
    delete ui;
}


void SensorWindow::on_NySensorkon_clicked()
{
    NySensorKonf *NSKWindow = new NySensorKonf;
    NSKWindow->show();
}

void SensorWindow::on_backButton_clicked()
{
    this->close();
}
