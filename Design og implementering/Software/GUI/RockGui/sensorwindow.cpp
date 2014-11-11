#include "sensorwindow.h"
#include "ui_sensorwindow.h"
#include "nysensorkonf.h"
#include "redigersensorkonfi.h"
#include "sletsensorkonf.h"

SensorWindow::SensorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SensorWindow)
{
    ui->setupUi(this);
}

SensorWindow::~SensorWindow()
{
    delete ui;
}

void SensorWindow::on_NySensorkon_clicked()
{
    NySensorkonf *NSKWindow = new NySensorkonf;
    NSKWindow->show();
}

void SensorWindow::on_RedigerSensorKon_clicked()
{
    RedigerSensorkonfi *RSKWindow = new RedigerSensorkonfi;
    RSKWindow->show();
}

void SensorWindow::on_SletSensorKon_clicked()
{
    SletSensorkonf *SSKWindow = new SletSensorkonf;
    SSKWindow->show();
}
