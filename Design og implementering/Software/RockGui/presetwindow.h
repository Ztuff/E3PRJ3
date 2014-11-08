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

private:
    Ui::PresetWindow *ui;
};

#endif // PRESETWINDOW_H
