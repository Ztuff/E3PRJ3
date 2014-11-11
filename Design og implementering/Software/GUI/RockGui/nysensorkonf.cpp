#include "nysensorkonf.h"
#include "ui_nysensorkonf.h"

NySensorkonf::NySensorkonf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NySensorkonf)
{
    ui->setupUi(this);
}

NySensorkonf::~NySensorkonf()
{
    delete ui;
}
