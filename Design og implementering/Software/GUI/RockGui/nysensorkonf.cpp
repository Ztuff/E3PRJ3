#include "nysensorkonf.h"
#include "ui_nysensorkonf.h"

NySensorkonf::NySensorkonf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NySensorkonf)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

NySensorkonf::~NySensorkonf()
{
    delete ui;
}

void NySensorkonf::on_backButton_clicked()
{
    this->close();
}
