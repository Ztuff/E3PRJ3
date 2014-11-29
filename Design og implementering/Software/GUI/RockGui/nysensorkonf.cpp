#include "nysensorkonf.h"
#include "ui_nysensorkonf.h"
#include "msghandling.h"

NySensorkonf::NySensorkonf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NySensorkonf)
{
    msghandling::DatabankInfoMsg sensInfo
            = static_cast<DatabankInfoMsg>(sendMsgWRelpy(Controller::GET_NEW_SENS_CONF_INFO, msghandling::DATA_BANK_INFO_MSG));
    sensInfo.sensorList;
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

NySensorkonf::~NySensorkonf()
{
    delete ui;
}

void NySensorkonf::on_backButton_clicked()
{
    this->close();
}

void NySensorkonf::on_Sensordropdown_activated(const QString &arg1)
{
    QComboBox* combo = new QComboBox;
    combo->addItems(DatabankInfoMsg.sensorListe);
}
