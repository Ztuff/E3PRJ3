#include "nypreset.h"
#include "ui_nypreset.h"

NyPreset::NyPreset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NyPreset)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

NyPreset::~NyPreset()
{
    delete ui;
}

void NyPreset::on_backButton_clicked()
{
    this->close();
}
