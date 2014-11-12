#ifndef REDIGERSENSORKONFI_H
#define REDIGERSENSORKONFI_H

#include <QWidget>

namespace Ui {
class RedigerSensorkonfi;
}

class RedigerSensorkonfi : public QWidget
{
    Q_OBJECT

public:
    explicit RedigerSensorkonfi(QWidget *parent = 0);
    ~RedigerSensorkonfi();

private slots:
    void on_backButton_clicked();

private:
    Ui::RedigerSensorkonfi *ui;
};

#endif // REDIGERSENSORKONFI_H
