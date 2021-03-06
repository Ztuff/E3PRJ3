#ifndef SLETPRESET_H
#define SLETPRESET_H

#include <QWidget>

namespace Ui {
class SletPreset;
}

class SletPreset : public QWidget
{
    Q_OBJECT

public:
    explicit SletPreset(QWidget *parent = 0);
    ~SletPreset();

private slots:
    void on_backButton_clicked();

private:
    Ui::SletPreset *ui;
};

#endif // SLETPRESET_H
