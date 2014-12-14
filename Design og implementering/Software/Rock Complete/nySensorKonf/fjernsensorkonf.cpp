#include "fjernsensorkonf.h"
#include "ui_fjernsensorkonf.h"

fjernsensorkonf::fjernsensorkonf(QWidget *parent, MsgHandler* msg) :
    QWidget(parent),
    ui(new Ui::fjernsensorkonf)
{
    msgH_ = msg;
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);
    SensorKonfInfo sensKonf = msgH_->getSensorKonfInfo();
    std::vector<std::string> sensVector = sensKonf.sensorNames;
    QStringList sensQStrings;
    for(int i = 0; i<sensVector.size(); i++)
    {
        QString str = QString::fromLocal8Bit(sensVector[i].c_str());
        sensQStrings << str;
    }
    ui->SensorKonfigurationList->addItems(sensQStrings);
}

fjernsensorkonf::~fjernsensorkonf()
{
    delete ui;
}

void fjernsensorkonf::on_saveButton_clicked()
{
    std::string condemned = ui->SensorKonfigurationList->currentItem()->text().toUtf8().constData();
    msgH_->deleteSensorKonf(condemned, " ", "", "", ""); //vi går kun efter navn
    this->close();
}

void fjernsensorkonf::on_backButton_clicked()
{
    this->close();
}
