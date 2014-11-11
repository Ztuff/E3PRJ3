#include "importerlydpakke.h"
#include "ui_importerlydpakke.h"

ImporterLydpakke::ImporterLydpakke(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImporterLydpakke)
{
    ui->setupUi(this);
}

ImporterLydpakke::~ImporterLydpakke()
{
    delete ui;
}
