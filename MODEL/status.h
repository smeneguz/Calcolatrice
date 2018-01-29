#ifndef STATUS_H
#define STATUS_H
#include <string>
#include <iostream>
// La classe Status ha lo scopo di fungere da trasportatore di dati. Per questo gli attributi sono stati dichiarati public

class Status{
public:
    //lunghezza
    int l;
    double lCm;
    double lInch;

    //altezza
    int h;
    double hCm;
    double hInch;


    //profondità
    int d;
    double dCm;
    double dInch;

    //dpi
    int dpi;

    //colore
    std::string color;


    //costruttore
    Status();
};

#endif // STATUS_H
