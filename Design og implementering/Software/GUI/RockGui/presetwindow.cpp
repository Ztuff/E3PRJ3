#include "presetwindow.h"
#include "ui_presetwindow.h"
#include "nypreset.h"
#include "redigerpreset.h"
#include "sletpreset.h"

PresetWindow::PresetWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PresetWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

PresetWindow::~PresetWindow()
{
    delete ui;
}

void PresetWindow::on_NytPreset_clicked()
{
    NyPreset *NPWindow = new NyPreset;
    NPWindow->show();
}

void PresetWindow::on_RedigerPreset_clicked()
{
    RedigerPreset *RPWinodw = new RedigerPreset;
    RPWinodw->show();
}

void PresetWindow::on_SletPreset_clicked()
{
    SletPreset *SPWindow = new SletPreset;
    SPWindow->show();
}

void PresetWindow::on_backButton_clicked()
{
    this->close();
}
