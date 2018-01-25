#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <typeinfo>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //RGBHex* b = new RGBHex ("0000F/F0o0"); //mi controlla in colore in esadecimale e pulisce la sctringa partendo dal fondo
    MainWindow m;
    m.show();

    return a.exec();
}
