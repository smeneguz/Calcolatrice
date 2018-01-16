#include "mainwindow.h"
#include <QApplication>
#include "MODEL/businesslogic.h"
#include <iostream>
#include <typeinfo>
#include "VIEW/colorrange.h"
#include "VIEW/createcolor.h"
#include "VIEW/colorzone.h"
#include "./VIEW/prova.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RGBHex* b = new RGBHex ("0000F/F0o0"); //mi controlla in colore in esadecimale e pulisce la sctringa partendo dal fondo

    std::cout << b->getColor();
    //devo usare la classe business logic
    Object* k = new Object_1D(4,3, *b);
    //Space* l = new Object_1D(4);

    //Space* j = new Object_2D(4,6);
    //Space* u = &(*(k) + *(j));
    //std::cout << u->getLength();
    std::cout << 1;
    ////USANDO BUSINESS
    //BusinessLogic bu = BusinessLogic();
    std::cout << 2;


    RGBHex r2 = RGBHex("0005AA");
    Object * op1 = k;
    Object* op2 = b;
    std::cout << 3;
    if (typeid(*op1)== typeid(Object_2D)) std::cout<< "uguali";
    //bu.setOp1(op1);
   // bu.setOp2(op2);
    //if (typeid(*(bu.getOp1()))== typeid(Object_2D)) std::cout<< "uguali";
    else std::cout << "diversi";

    //if (typeid(*(bu.getOp2()))== typeid(RGBHex)) std::cout<< "uguali";

    //bu.setOperator(1);
   // bu.esegui();
    //Status s1 = bu.getRisultato()->getStatus();
    //std::cout << s1.color << "  "<<s1.d << "   "<< s1.l;

    //Prova* as= new Prova();

    //MainWindow w;
    //as->show();
//problema con operazioni che hanno come secondo operando colore
    return a.exec();
}
