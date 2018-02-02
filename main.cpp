#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <typeinfo>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow m;
    m.show();


    return a.exec();
}
