#include "mainwindow.h"
#include <QApplication>
#include "MODEL/space.h"
#include<iostream>
#include "MODEL/object_1d.h"
#include"MODEL/object_2d.h"
#include"MODEL/object_3d.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    RGBHex* b = new RGBHex ("0000F/F0o0"); //mi controlla in colore in esadecimale e pulisce la sctringa partendo dal fondo

    std::cout << b->getColor();
    //devo usare la classe business logic
    Space* k = new Object_1D();
    Space* l = new Object_1D(4);
    Space* f = &(*(k) + *(l));//non da errori (somma tra oggetti puntati e poi riferimento a quell'oggetto)
    std::cout << f->getLength();
    //std::cout << l->getLength();
    //oggetti diversi
    Space* j = new Object_2d(4,6);
    Space* u = &(*(k) + *(j));
    std::cout << u->getLength();


    return a.exec();
}
