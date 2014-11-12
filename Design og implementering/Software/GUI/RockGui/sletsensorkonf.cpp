#include "sletsensorkonf.h"
#include "ui_sletsensorkonf.h"

SletSensorkonf::SletSensorkonf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SletSensorkonf)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

SletSensorkonf::~SletSensorkonf()
{
    delete ui;
}

void SletSensorkonf::on_backButton_clicked()
{
    this->close();
}
