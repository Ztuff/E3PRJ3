#include "lydpakkerwindow.h"
#include "ui_lydpakkerwindow.h"
#include "importerlydpakke.h"
#include "sletlydpakke.h"

LydpakkerWindow::LydpakkerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LydpakkerWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
}

LydpakkerWindow::~LydpakkerWindow()
{
    delete ui;
}

void LydpakkerWindow::on_ImporterLydpakke_clicked()
{
    ImporterLydpakke *ILWindow = new ImporterLydpakke;
    ILWindow->show();
}

void LydpakkerWindow::on_SletLydpakke_clicked()
{
    SletLydpakke *SLWindow = new SletLydpakke;
    SLWindow->show();
}

void LydpakkerWindow::on_backButton_clicked()
{
    this->close();
}
