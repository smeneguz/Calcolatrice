#ifndef COLORE_H
#define COLORE_H

#include<iostream>
/**
 * @brief la classe Color svolge il compito di interfaccia per permettere estensibilità
 */
class Color{


public:
   // virtual std::string getHex() const = 0;
    virtual ~Color();
    virtual Color* clone() const =0;

    // operatori che verranno chiamati e implementati nella classe rgb
    virtual Color& operator+(const Color& x) = 0;
    virtual Color& operator-(const Color& x) = 0;
    virtual Color& operator*(const Color& x) = 0;
    virtual Color& operator/(const Color& x) = 0;

};

#endif // COLORE_H
