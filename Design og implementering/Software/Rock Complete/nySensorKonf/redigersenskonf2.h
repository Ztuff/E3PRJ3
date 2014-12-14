#ifndef REDIGERSENSKONF2_H
#define REDIGERSENSKONF2_H

#include <QWidget>
#include "MsgHandler.hpp"

namespace Ui {
class redigersenskonf2;
}

class redigersenskonf2 : public QWidget
{
    Q_OBJECT

public:
    redigersenskonf2(QWidget *parent, MsgHandler* msg, QString sensorName);
    ~redigersenskonf2();

private slots:
    void on_backButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::redigersenskonf2 *ui;
    MsgHandler* msgH_;
};

#endif // REDIGERSENSKONF2_H
