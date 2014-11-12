#include "importerlydpakke.h"
#include "ui_importerlydpakke.h"

ImporterLydpakke::ImporterLydpakke(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImporterLydpakke)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

ImporterLydpakke::~ImporterLydpakke()
{
    delete ui;
}

void ImporterLydpakke::on_backButton_clicked()
{
    this->close();
}
