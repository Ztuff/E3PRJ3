#ifndef REDIGERPRESET_H
#define REDIGERPRESET_H

#include <QWidget>

namespace Ui {
class RedigerPreset;
}

class RedigerPreset : public QWidget
{
    Q_OBJECT

public:
    explicit RedigerPreset(QWidget *parent = 0);
    ~RedigerPreset();

private slots:
    void on_backButton_clicked();

private:
    Ui::RedigerPreset *ui;
};

#endif // REDIGERPRESET_H
