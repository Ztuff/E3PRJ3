#include "redigersensorkonfi.h"
#include "ui_redigersensorkonfi.h"

RedigerSensorkonfi::RedigerSensorkonfi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RedigerSensorkonfi)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

RedigerSensorkonfi::~RedigerSensorkonfi()
{
    delete ui;
}

void RedigerSensorkonfi::on_backButton_clicked()
{
    this->close();
}
