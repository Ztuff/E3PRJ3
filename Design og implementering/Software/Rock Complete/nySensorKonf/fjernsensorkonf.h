#ifndef FJERNSENSORKONF_H
#define FJERNSENSORKONF_H

#include <QWidget>
#include "MsgHandler.hpp"

namespace Ui {
class fjernsensorkonf;
}

class fjernsensorkonf : public QWidget
{
    Q_OBJECT

public:
    fjernsensorkonf(QWidget *parent, MsgHandler* msg);
    ~fjernsensorkonf();

private slots:
    void on_saveButton_clicked();

    void on_backButton_clicked();

private:
    Ui::fjernsensorkonf *ui;
    MsgHandler* msgH_;
};

#endif // FJERNSENSORKONF_H
