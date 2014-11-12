#ifndef SENSORLISTE_H
#define SENSORLISTE_H

#include <QWidget>

namespace Ui {
class SensorListe;
}

class SensorListe : public QWidget
{
    Q_OBJECT

public:
    explicit SensorListe(QWidget *parent = 0);
    ~SensorListe();

private:
    Ui::SensorListe *ui;
};

#endif // SENSORLISTE_H
