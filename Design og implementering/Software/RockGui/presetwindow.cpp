#include "presetwindow.h"
#include "ui_presetwindow.h"

PresetWindow::PresetWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PresetWindow)
{
    ui->setupUi(this);
}

PresetWindow::~PresetWindow()
{
    delete ui;
}
