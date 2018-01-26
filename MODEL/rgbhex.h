#ifndef RGBHEX_H
#define RGBHEX_H
#include <math.h>
#include<iostream>
#include "object.h"
/**
 * @brief La classe RGBHex rappresenta i colori in formato esadecimale avendo in input una stringa o un intero
 */
class RGBHex : public Object{
private:
    int color;
    static const char c[];
    // Questa funione serve solo per pulire una stringa e mantenere solo i caratteri esadecimali
    // Inoltre, posso scegliere tramite intero n quanti caratteri mantenere (a partire dal FONDO della stringa)
    static std::string puliStringa(std::string s, int n=6);
    // Questa funzione serve a convertire gli ultimi n caratteri di una stringa esadecimale in intero
    static int valueOf(std::string c, int n);
public:


    RGBHex();
    RGBHex(std::string c);
    RGBHex(int r, int g, int b);
    //virtual ~RGBHex(); non devo metterlo perchè fa la distruzione di default di un primitivo int

    //metodi set e get
    void setColor(std::string c);
    void setColorInt(int c);
    std::string getColor() const;
    int getColorInt() const;

    //set rgb versione string
    void setR(std::string r);
    void setG(std::string g);
    void setB(std::string b);
    std::string getR() const;
    std::string getG() const;
    std::string getB() const;

    //set rgb versione int
    void setRint(int r); // 0<r<255
    void setGint(int g); // 0<g<255
    void setBint(int b); // 0<b<255
    int getRint() const; // return x| 0<x<255
    int getGint() const; // return x| 0<x<255
    int getBint() const; // return x| 0<x<255
    virtual Status getStatus() const;


    // Overloading di operatori
    RGBHex operator+(const RGBHex& x);
    RGBHex operator-(const RGBHex& x);
    RGBHex operator*(const RGBHex& x);
    RGBHex operator/(const RGBHex& x);


};

#endif // RGBHEX_H
