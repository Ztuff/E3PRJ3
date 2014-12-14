#ifndef REDIGERSENSKONF_H
#define REDIGERSENSKONF_H

#include <QWidget>
#include "MsgHandler.hpp"

namespace Ui {
class redigersenskonf;
}

class redigersenskonf : public QWidget
{
    Q_OBJECT

public:
    redigersenskonf(QWidget *parent, MsgHandler* msg);
    ~redigersenskonf();

private slots:
    void on_backButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::redigersenskonf *ui;
    MsgHandler* msgH_;
};

#endif // REDIGERSENSKONF_H
