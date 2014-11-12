#ifndef NYPRESET_H
#define NYPRESET_H

#include <QWidget>

namespace Ui {
class NyPreset;
}

class NyPreset : public QWidget
{
    Q_OBJECT

public:
    explicit NyPreset(QWidget *parent = 0);
    ~NyPreset();

private slots:
    void on_backButton_clicked();

private:
    Ui::NyPreset *ui;
};

#endif // NYPRESET_H
