#include "redigersenskonf.h"
#include "ui_redigersenskonf.h"
#include "redigersenskonf2.h"

redigersenskonf::redigersenskonf(QWidget *parent, MsgHandler *msg) :
    QWidget(parent),
    ui(new Ui::redigersenskonf)
{
    msgH_ = msg;
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
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

redigersenskonf::~redigersenskonf()
{
    delete ui;
}

void redigersenskonf::on_backButton_clicked()
{
    this->close();
}

void redigersenskonf::on_saveButton_clicked()
{
    QString sensorConfigurationName = ui->SensorKonfigurationList->currentItem()->text();
    QWidget* parent = 0;
    redigersenskonf2 *window = new redigersenskonf2(parent, msgH_, sensorConfigurationName);
    window->show();
}
