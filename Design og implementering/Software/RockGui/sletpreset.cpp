#include "sletpreset.h"
#include "ui_sletpreset.h"

SletPreset::SletPreset(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SletPreset)
{
    ui->setupUi(this);
}

SletPreset::~SletPreset()
{
    delete ui;
}
