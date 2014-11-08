#ifndef NYSENSORKONF_H
#define NYSENSORKONF_H

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

private:
    Ui::NySensorkonf *ui;
};

#endif // NYSENSORKONF_H
