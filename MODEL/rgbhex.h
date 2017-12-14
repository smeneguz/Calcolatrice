#ifndef RGBHEX_H
#define RGBHEX_H

#include "color.h"

class rgbHex : public Color {
protected:
    int color;
    static const char c[];
public:
    rgbHex();
    rgbHex(std::string c);
    rgbHex(int r, int g, int b);

    //metodi set e get
    void setColor(std::string c);
    void setColorInt(int color);
    std::string getColor() const;
    int getColorInt() const;

    //serve metodo per getinfo da

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

    // Overloading di operatori
    rgbHex operator+(const rgbHex& x);
    rgbHex operator-(const rgbHex& x);
    rgbHex operator*(const rgbHex& x);
    rgbHex operator/(const rgbHex& x);


    /* DA IMPLEMENTARE
     * virtual std::string getHex() const = 0;
     * virtual ~Colore()=0;
     * virtual Colore* clone() const =0;
     *
     */

};

#endif // RGBHEX_H
