#ifndef COLORE_H
#define COLORE_H

#include<iostream>

class Colore{
public:
    virtual std::string getHex() const = 0;
    virtual ~Colore()=0;
    virtual Colore* clone() const =0;
};

#endif // COLORE_H
