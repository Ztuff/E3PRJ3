#ifndef NYSENSORKONF_H
#define NYSENSORKONF_H

#include <QWidget>

namespace Ui {
class NySensorKonf;
}

class NySensorKonf : public QWidget
{
    Q_OBJECT

public:
    explicit NySensorKonf(QWidget *parent = 0);
    ~NySensorKonf();

private slots:
    void on_backButton_clicked();

    void on_Sensordropdown_activated(const QString &arg1);

    void on_saveButton_clicked();

private:
    Ui::NySensorKonf *ui;
};

#endif // NYSENSORKONF_H
