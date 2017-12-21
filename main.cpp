#include "mainwindow.h"
#include <QApplication>
#include "MODEL/space.h"
#include<iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    RGBHex* b = new RGBHex ("0000F/F0o0"); //mi controlla in colore in esadecimale e pulisce la sctringa partendo dal fondo
    std::cout << b->getColor();


    return a.exec();
}
