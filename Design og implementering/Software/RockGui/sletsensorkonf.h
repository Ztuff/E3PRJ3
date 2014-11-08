#ifndef SLETSENSORKONF_H
#define SLETSENSORKONF_H

#include <QWidget>

namespace Ui {
class SletSensorkonf;
}

class SletSensorkonf : public QWidget
{
    Q_OBJECT

public:
    explicit SletSensorkonf(QWidget *parent = 0);
    ~SletSensorkonf();

private:
    Ui::SletSensorkonf *ui;
};

#endif // SLETSENSORKONF_H
