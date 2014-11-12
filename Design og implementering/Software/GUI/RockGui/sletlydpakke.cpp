#include "sletlydpakke.h"
#include "ui_sletlydpakke.h"

SletLydpakke::SletLydpakke(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SletLydpakke)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

SletLydpakke::~SletLydpakke()
{
    delete ui;
}

void SletLydpakke::on_backButton_clicked()
{
    this->close();
}
