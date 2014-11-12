#include "sensorliste.h"
#include "ui_sensorliste.h"

SensorListe::SensorListe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SensorListe)
{
    ui->setupUi(this);
}

SensorListe::~SensorListe()
{
    delete ui;
}
