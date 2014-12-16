#include "redigersenskonf2.h"
#include "ui_redigersenskonf2.h"
#include <vector>
#include <string>

using namespace std;

redigersenskonf2::redigersenskonf2(QWidget *parent, MsgHandler* msg, QString sensorName) :
    QWidget(parent),
    ui(new Ui::redigersenskonf2)
{
    msgH_ = msg;
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
    ui->SensorName->setText(sensorName);
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

redigersenskonf2::~redigersenskonf2()
{
    delete ui;
}

void redigersenskonf2::on_backButton_clicked()
{
    this->close();
}

void redigersenskonf2::on_saveButton_clicked()
{
    string namevalg = ui->SensorName->text().toUtf8().constData();
    string sensorvalg = ui->Sensordropdown->currentText().toUtf8().constData();
    string MSchemeValg = ui->MappingschemeDropdown->currentText().toUtf8().constData();
    string AkseValg = ui->AkseDropdown->currentText().toUtf8().constData();
    string LydpakkeValg = ui->LydpakkeDropdown->currentText().toUtf8().constData();
    msgH_->deleteSensorKonf(namevalg, sensorvalg, MSchemeValg, AkseValg, LydpakkeValg); //Det er kun sensorkonfigurationen med samme navn der slettes
    msgH_->setSensorKonf(namevalg, sensorvalg, MSchemeValg, AkseValg, LydpakkeValg);
    this->close();
}
