#include "lydpakkerwindow.h"
#include "ui_lydpakkerwindow.h"
#include "importerlydpakke.h"
#include "sletlydpakke.h"
LydpakkerWindow::LydpakkerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LydpakkerWindow)
{
    ui->setupUi(this);
}

LydpakkerWindow::~LydpakkerWindow()
{
    delete ui;
}

void LydpakkerWindow::on_ImporterLydpakke_clicked()
{

}
