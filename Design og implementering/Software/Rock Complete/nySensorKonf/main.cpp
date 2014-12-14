#include "mainwindow.h"
#include <QApplication>
#include "Controller.hpp"
#include "MsgHandler.hpp"

Controller cont;
MsgHandler msgH(cont.getMsgQueue());

int main(int argc, char *argv[])
{
    cont.start();
    QApplication a(argc, argv);
    QWidget* p = 0;
    MainWindow w(p, &msgH);
    w.show();

    return a.exec();
}


