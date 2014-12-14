#ifndef NYSENSORKONF_H
#define NYSENSORKONF_H

#include <QWidget>
#include "MsgHandler.hpp"

namespace Ui {
class NySensorKonf;
}

class NySensorKonf : public QWidget
{
    Q_OBJECT

public:
    NySensorKonf(QWidget* parent, MsgHandler* msg);
    ~NySensorKonf();

private slots:
    void on_backButton_clicked();

    void on_Sensordropdown_activated(const QString &arg1);

    void on_saveButton_clicked();

private:
    Ui::NySensorKonf *ui;
    MsgHandler* msgH_;
};

#endif // NYSENSORKONF_H
