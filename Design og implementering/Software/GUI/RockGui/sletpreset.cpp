#include "sletpreset.h"
#include "ui_sletpreset.h"

SletPreset::SletPreset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SletPreset)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

SletPreset::~SletPreset()
{
    delete ui;
}

void SletPreset::on_backButton_clicked()
{
    this->close();
}
