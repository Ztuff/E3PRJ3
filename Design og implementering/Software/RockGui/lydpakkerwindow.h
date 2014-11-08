#ifndef LYDPAKKERWINDOW_H
#define LYDPAKKERWINDOW_H

#include <QWidget>

namespace Ui {
class LydpakkerWindow;
}

class LydpakkerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LydpakkerWindow(QWidget *parent = 0);
    ~LydpakkerWindow();

private slots:
    void on_pushButton_clicked();

    void on_ImporterLydpakke_clicked();

private:
    Ui::LydpakkerWindow *ui;
};

#endif // LYDPAKKERWINDOW_H
