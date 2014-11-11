#include "sletlydpakke.h"
#include "ui_sletlydpakke.h"

SletLydpakke::SletLydpakke(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SletLydpakke)
{
    ui->setupUi(this);
}

SletLydpakke::~SletLydpakke()
{
    delete ui;
}
