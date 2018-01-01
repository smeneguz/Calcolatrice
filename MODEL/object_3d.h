#ifndef OBJECT_3D_H
#define OBJECT_3D_H
#include "space.h"

class Object_3D : public Space{
private:
    int length; //lunghezza in pixel
    int height; // altezza in pixel
    int depth; //profondità in pixel
    //nel caso in cui uno dei due campi venga istanziato a 0 si solleva un eccezzione, nel caso uno dei due sia 1 allora viene visto come oggetto a una dimension
public:
    Object_3D();
    Object_3D(int l);
    Object_3D(int l, int h);
    Object_3D(int l, int h, int d);
    Object_3D(int l, int h, int d, int risol);
    Object_3D(int l, int h, int d, int risol, RGBHex c);

    virtual int CalcolaSuperficie();
    virtual Status getStatus() const;

    //metodi get set campi dati
    int getLength() const;
    void setLength(int l);
    int getHeight() const;
    void setHeight(int h);
    int getDepth() const;
    void setDepth(int d);

    // Overloading di operatori
    Object_3D& operator+(const Space& x);
    Object_3D& operator-(const Space& x);
    Object_3D& operator*(const Space& x);
    Object_3D& operator/(const Space& x);

    //Operator Oggetto 2 dimensioni con colore
    Object_3D& operator+(const RGBHex& x);
    Object_3D& operator-(const RGBHex& x);
    Object_3D& operator*(const RGBHex& x);
    Object_3D& operator/(const RGBHex& x);

    //conversioni lunghezza && altezza && profondità in cm e inch
    void setLCm(double l);
    double getLCm() const;
    void setLInch(double l);
    double getLInch() const;
    void setHCm(double h);
    double getHCm() const;
    void setHInch(double h);
    double getHInch() const;
    void setDCm(double d);
    double getDCm() const;
    void setDInch(double d);
    double getDInch() const;


};

#endif // OBJECT_3D_H
