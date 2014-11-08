#include "redigersensorkonfi.h"
#include "ui_redigersensorkonfi.h"

RedigerSensorkonfi::RedigerSensorkonfi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RedigerSensorkonfi)
{
    ui->setupUi(this);
}

RedigerSensorkonfi::~RedigerSensorkonfi()
{
    delete ui;
}
