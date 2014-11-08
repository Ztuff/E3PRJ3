#ifndef SENSORWINDOW_H
#define SENSORWINDOW_H

#include <QWidget>

namespace Ui {
class SensorWindow;
}

class SensorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SensorWindow(QWidget *parent = 0);
    ~SensorWindow();

private slots:
    void on_pushButton_clicked();

    void on_NySensorkon_clicked();

    void on_RedigerSensorKon_clicked();

    void on_SletSensorKon_clicked();

private:
    Ui::SensorWindow *ui;
};

#endif // SENSORWINDOW_H
