#include "nysensorkonf.h"
#include "ui_nysensorkonf.h"
#include <QStringList>
#include <vector>
#include <QString>
#include <qmessagebox.h>
#include <QDebug>

using namespace std;

NySensorKonf::NySensorKonf(QWidget *parent, MsgHandler *msg) :
    QWidget(parent),
    ui(new Ui::NySensorKonf)
{
    msgH_ = msg;
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
    QStringList akser;
    QStringList sensorer;
    QStringList mSchemes;
    QStringList sPacks;
    SensorKonfInfo sensorKonf = msgH_->getSensorKonfInfo();
    vector<string> mappingSchemes = sensorKonf.mSchemes;
    vector<string> soundPacks = sensorKonf.lydpakker;

    for(unsigned int i = 0; i <mappingSchemes.size(); i++)
    {
        QString str = QString::fromLocal8Bit(mappingSchemes[i].c_str());
        mSchemes << str;
    }
    for(unsigned int i = 0; i<soundPacks.size(); i++)
    {
        QString str = QString::fromLocal8Bit(soundPacks[i].c_str());
        sPacks << str;
    }

    sensorer << "Accelerometer" << "Gyroskop";
    akser << "x" << "y" << "z";
    ui->Sensordropdown->addItems(sensorer);
    ui->MappingschemeDropdown->addItems(mSchemes);
    ui->AkseDropdown->addItems(akser);
    ui->LydpakkeDropdown->addItems(sPacks);
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
    string namevalg = ui->SensorName->text().toUtf8().constData();
    string sensorvalg = ui->Sensordropdown->currentText().toUtf8().constData();
    string MSchemeValg = ui->MappingschemeDropdown->currentText().toUtf8().constData();
    string AkseValg = ui->AkseDropdown->currentText().toUtf8().constData();
    string LydpakkeValg = ui->LydpakkeDropdown->currentText().toUtf8().constData();
    msgH_->setSensorKonf(namevalg, sensorvalg, AkseValg, MSchemeValg, LydpakkeValg);
    this->close();
}
