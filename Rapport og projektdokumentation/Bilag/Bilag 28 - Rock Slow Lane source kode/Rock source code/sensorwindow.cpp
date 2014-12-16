#include "sensorwindow.h"
#include "ui_sensorwindow.h"
#include "nysensorkonf.h"
#include "redigersenskonf.h"
#include "fjernsensorkonf.h"

SensorWindow::SensorWindow(QWidget *parent, MsgHandler* msg) :
    QWidget(parent),
    ui(new Ui::SensorWindow)
{
    msgH_ = msg;
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

SensorWindow::~SensorWindow()
{
    delete ui;
}


void SensorWindow::on_NySensorkon_clicked()
{
    QWidget* parent = 0;
    NySensorKonf *NSKWindow = new NySensorKonf(parent, msgH_);
    NSKWindow->show();
}

void SensorWindow::on_backButton_clicked()
{
    this->close();
}

void SensorWindow::on_RedigerSensorKon_clicked()
{
    QWidget* parent = 0;
    redigersenskonf *window = new redigersenskonf(parent, msgH_);
    window->show();
}

void SensorWindow::on_SletSensorKon_clicked()
{
    QWidget* parent = 0;
    fjernsensorkonf *window = new fjernsensorkonf(parent, msgH_);
    window->show();
}
