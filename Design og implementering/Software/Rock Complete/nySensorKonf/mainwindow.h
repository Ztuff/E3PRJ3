#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MsgHandler.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, MsgHandler* msgH);
    ~MainWindow();

private slots:
    void on_Sensorer_clicked();

    void on_Lydpakker_clicked();

    void on_Presets_clicked();

    void on_CloseButton_clicked();

private:
    Ui::MainWindow *ui;
    MsgHandler* msgH_;

};

#endif // MAINWINDOW_H
