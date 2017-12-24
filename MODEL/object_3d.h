#ifndef OBJECT_3D_H
#define OBJECT_3D_H
#include "space.h"

class Object_3d : public Space{
private:
    int length; //lunghezza in pixel
    int height; // altezza in pixel
    int depth; //profondità in pixel
    //nel caso in cui uno dei due campi venga istanziato a 0 si solleva un eccezzione, nel caso uno dei due sia 1 allora viene visto come oggetto a una dimension
public:
    Object_3d();
    Object_3d(int l);
    Object_3d(int l, int h);
    Object_3d(int l, int h, int d);
    Object_3d(int l, int h, int d, int risol);
    Object_3d(int l, int h, int d, int risol, RGBHex c);

    //metodi get set campi dati
    int getLength() const;
    void setLength(int l);
    // Overloading di operatori
    Object_3d& operator+(const Space& x);
    Object_3d& operator-(const Space& x);
    Object_3d& operator*(const Space& x);
    Object_3d& operator/(const Space& x);
    //Operator Oggetto 2 dimensioni con colore
    Object_3d& operator+(const RGBHex& x);
    Object_3d& operator-(const RGBHex& x);
    Object_3d& operator*(const RGBHex& x);
    Object_3d& operator/(const RGBHex& x);

};

#endif // OBJECT_3D_H
