#ifndef COLORE_H
#define COLORE_H

#include<iostream>

class Color{
protected:
    int color;
    static const char c[];
public:
    virtual std::string getHex() const = 0;
    virtual ~Color();
    virtual Color* clone() const =0;

    // operatori che verranno chiamati e implementati nella classe rgb


};

#endif // COLORE_H
