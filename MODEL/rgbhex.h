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
    // Questa funione serve solo per pulire una stringa e mantenere solo i charatteri esadecimali
    // Inoltre, posso scegliere tramite intero n quanti charatteri mantenere (a partire dal FONDO della stringa)
    static std::string pulisciS(std::string s, int n=6);
    // Questa funzione serve a convertire gli ultimi n charatteri di una stringa esadecimale in intero
    static int valoreS(std::string c, int n);
public:


    RGBHex();
    //costruttore tramite stringa
    RGBHex(std::string c);
    //costruttore tr amite 3 int
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

    //get r g b string
    std::string getR() const;
    std::string getG() const;
    std::string getB() const;

    //set rgb versione int
    void setRint(int r); // 0<r<255
    void setGint(int g); // 0<g<255
    void setBint(int b); // 0<b<255

    //get r g b
    int getRint() const; // return x| 0<x<255
    int getGint() const; // return x| 0<x<255
    int getBint() const; // return x| 0<x<255

    //status di RGBhex
    virtual Status getStatus() const;


    // Overloading di operatori
    RGBHex operator+(const RGBHex& x);
    RGBHex operator-(const RGBHex& x);
    RGBHex operator*(const RGBHex& x);
    RGBHex operator/(const RGBHex& x);


};

#endif // RGBHEX_H
