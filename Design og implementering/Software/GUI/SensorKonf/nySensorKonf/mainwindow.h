#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Sensorer_clicked();

    void on_Lydpakker_clicked();

    void on_Presets_clicked();

    void on_CloseButton_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
