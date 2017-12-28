#ifndef STATUS_H
#define STATUS_H
#include <string>
#include <iostream>
// La classe Status ha lo scopo di fungere da trasportatore di dati. Per questo gli attributi sono stati dichiarati public

class Status{
public:
    int l;
    double lCm;
    double lInch;
    int h;
    double hCm;
    double hInch;
    int d;
    double dCm;
    double dInch;
    int dpi;
    std::string color;

    Status();
};

#endif // STATUS_H
