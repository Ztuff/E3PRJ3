#ifndef SENSORWINDOW_H
#define SENSORWINDOW_H

#include <QWidget>
#include "MsgHandler.hpp"

namespace Ui {
class SensorWindow;
}

class SensorWindow : public QWidget
{
    Q_OBJECT

public:
    SensorWindow(QWidget *parent, MsgHandler* msg);
    ~SensorWindow();

private slots:
    void on_backButton_clicked();

    void on_NySensorkon_clicked();

    void on_RedigerSensorKon_clicked();

    void on_SletSensorKon_clicked();

private:
    Ui::SensorWindow *ui;
    MsgHandler* msgH_;
};

#endif // SENSORWINDOW_H
