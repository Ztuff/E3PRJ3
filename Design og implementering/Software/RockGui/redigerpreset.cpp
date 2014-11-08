#include "redigerpreset.h"
#include "ui_redigerpreset.h"

RedigerPreset::RedigerPreset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RedigerPreset)
{
    ui->setupUi(this);
}

RedigerPreset::~RedigerPreset()
{
    delete ui;
}
