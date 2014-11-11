#include "sletsensorkonf.h"
#include "ui_sletsensorkonf.h"

SletSensorkonf::SletSensorkonf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SletSensorkonf)
{
    ui->setupUi(this);
}

SletSensorkonf::~SletSensorkonf()
{
    delete ui;
}
