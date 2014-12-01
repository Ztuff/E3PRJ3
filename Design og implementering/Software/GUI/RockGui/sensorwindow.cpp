#include "sensorwindow.h"
#include "ui_sensorwindow.h"
#include "nysensorkonf.h"
#include "redigersensorkonfi.h"
#include "sletsensorkonf.h"
#include "msghandling.h"

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
    NySensorkonf *NSKWindow = new NySensorkonf;
    sendMsgWReply();
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

void SensorWindow::on_backButton_clicked()
{
    this->close();
}
