#ifndef OBJECT_1D_H
#define OBJECT_1D_H

#include "space.h"
/**
 * @brief La classe Object_1D rappresenta un oggetto collocabile su una dimensione (es. punto, linea..)
 */
class Object_1D : public Space {
private:
    int length;//lunghezza in pixel ((se la lunghezza è pari a 0 solleva eccezione &&  se 1px è un punto) altrimenti è una linea)
public:
    Object_1D();
    Object_1D(int l);
    Object_1D(int risol, int l);
    Object_1D(int risol, RGBHex c, int l);

    virtual int CalcolaSuperficie();

    //set e get
    int getLength() const;
    void setLength(int l);

    // Overloading di operatori (oggetto a una dimensione + - * / oggetto a una dimensione)
    Object_1D& operator+(const Space& x);
    Object_1D& operator-(const Space& x);
    Object_1D& operator*(const Space& x);
    Object_1D& operator/(const Space& x);

    //Overloading di overriding (oggetto una dimensione + - * / colore)
    Object_1D& operator+(const RGBHex& x);
    Object_1D& operator-(const RGBHex& x);
    Object_1D& operator*(const RGBHex& x);
    Object_1D& operator/(const RGBHex& x);

    //conversioni lunghezza in cm e inch
    void setLCm(double l);
    double getLCm() const;
    void setLInch(double l);
    double getLInch() const;

};

#endif // OBJECT_1D_H
