#ifndef NYSENSORKONF_H
#define NYSENSORKONF_H
#include <vector>
#include "MsgQueue.hpp"
#include <string>
#include <QWidget>

namespace Ui {
class NySensorkonf;
}

class NySensorkonf : public QWidget
{
    Q_OBJECT

public:
    explicit NySensorkonf(QWidget *parent = 0);
    ~NySensorkonf();

private slots:
    void on_backButton_clicked();

    void on_Sensordropdown_activated(const QString &arg1);

private:
    Ui::NySensorkonf *ui;
};

#endif // NYSENSORKONF_H
