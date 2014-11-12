#ifndef PRESETWINDOW_H
#define PRESETWINDOW_H

#include <QWidget>

namespace Ui {
class PresetWindow;
}

class PresetWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PresetWindow(QWidget *parent = 0);
    ~PresetWindow();

private slots:
    void on_NytPreset_clicked();

    void on_RedigerPreset_clicked();

    void on_SletPreset_clicked();

    void on_backButton_clicked();

private:
    Ui::PresetWindow *ui;
};

#endif // PRESETWINDOW_H
