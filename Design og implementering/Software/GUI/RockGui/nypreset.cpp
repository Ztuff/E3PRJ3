#include "nypreset.h"
#include "ui_nypreset.h"

NyPreset::NyPreset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NyPreset)
{
    ui->setupUi(this);
}

NyPreset::~NyPreset()
{
    delete ui;
}
