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

private slots:
    void on_backButton_clicked();

private:
    Ui::NySensorkonf *ui;
};

#endif // NYSENSORKONF_H
