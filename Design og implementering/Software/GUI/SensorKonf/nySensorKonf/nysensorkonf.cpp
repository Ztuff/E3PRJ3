#include "nysensorkonf.h"
#include "ui_nysensorkonf.h"
#include <QStringList>
#include <vector>
#include <QString>
#include <qmessagebox.h>
#include <QDebug>



using namespace std;

NySensorKonf::NySensorKonf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NySensorKonf)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    QStringList akser;
    QStringList sensorer;
    QStringList test;
    sensorer << "Accelerometer" << "Gyroskop";
    akser << "x" << "y" << "z";
    test << "sads" << "sadsa";
    ui->Sensordropdown->addItems(sensorer);
    ui->MappingschemeDropdown->addItems(test);
    ui->AkseDropdown->addItems(akser);
    ui->LydpakkeDropdown->addItems(test);
}

NySensorKonf::~NySensorKonf()
{
    delete ui;
}

void NySensorKonf::on_backButton_clicked()
{
    this->close();
}



void NySensorKonf::on_saveButton_clicked()
{
    QString sensorvalg = ui->Sensordropdown->currentText();
    QString MSchemeValg = ui->MappingschemeDropdown->currentText();
    QString AkseValg = ui->AkseDropdown->currentText();
    QString LydpakkeValg = ui->LydpakkeDropdown->currentText();
    QStringList SensorKonf;
    //SensorKonf << sensorvalg << MSchemeValg << MParameterValg <<LydpakkeValg;

    //qDebug() << SensorKonf() ;
    //QMessageBox::information(this, "title", SensorKonf);
}
