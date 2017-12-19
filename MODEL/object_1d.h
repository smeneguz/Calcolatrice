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
    Object_1D(int l, int risol);
    Object_1D(int l, int risol, StrategyColor* c);

    //conversioni lunghezza in cm e inch
    void setLungCm(double l);
    double getLungCm() const;
    void setLungInch(double l);
    double getLungInch() const;

    // Overloading di operatori
    Object_1D operator+(const Object_1D& x);
    Object_1D operator-(const Object_1D& x);
    Object_1D operator*(const Object_1D& x);
    Object_1D operator/(const Object_1D& x);

};

#endif // OBJECT_1D_H
