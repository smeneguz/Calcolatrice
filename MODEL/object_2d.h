#ifndef OBJECT_2D_H
#define OBJECT_2D_H

#include"space.h"

class Object_2d : public Space{
private:
    int length; //lunghezza in pixel
    int height; // altezza in pixel
    //nel caso in cui uno dei due campi venga istanziato a 0 si solleva un eccezzione, nel caso uno dei due sia 1 allora viene visto come oggetto a una dimensione

public:

    Object_2d();
    Object_2d(int l);
    Object_2d(int l, int risol);
    Object_2d(int risol, StrategyColor* c, int l, int h);

    //conversioni lunghezza in cm e inch
    void setLungCm(double l);
    double getLungCm() const;
    void setLungInch(double l);
    double getLungInch() const;

    // Overloading di operatori
    Object_2d operator+(const Object_2d& x);
    Object_2d operator-(const Object_2d& x);
    Object_2d operator*(const Object_2d& x);
    Object_2d operator/(const Object_2d& x);

};

#endif // OBJECT_2D_H
