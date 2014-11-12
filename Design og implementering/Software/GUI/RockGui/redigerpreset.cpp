#include "redigerpreset.h"
#include "ui_redigerpreset.h"

RedigerPreset::RedigerPreset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RedigerPreset)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

RedigerPreset::~RedigerPreset()
{
    delete ui;
}

void RedigerPreset::on_backButton_clicked()
{
    this->close();
}
