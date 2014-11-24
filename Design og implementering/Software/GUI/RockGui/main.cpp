#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "msghandling.h"
#include "MsgQueue.hpp"


using namespace std;

int main(int argc, char *argv[])
{
    Controller controlObject();
    controlObject.start();
    MsgHandling msgHandler(controlObject.getMsgQueue());


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
