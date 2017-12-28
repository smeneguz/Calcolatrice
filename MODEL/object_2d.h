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
    Object_2d(int l, int h);
    Object_2d(int l, int h, int risol);
    Object_2d(int l, int h, int risol, RGBHex c);

    virtual int CalcolaSuperficie();
    virtual Status getStatus() const;

    //metodi get set campi dati
    int getLength() const;
    void setLength(int l);
    int getHeight() const;
    void setHeight(int h);

    // Overloading di operatori
    Object_2d& operator+(const Space& x);
    Object_2d& operator-(const Space& x);
    Object_2d& operator*(const Space& x);
    Object_2d& operator/(const Space& x);

    //Operator Oggetto 2 dimensioni con colore
    Object_2d& operator+(const RGBHex& x);
    Object_2d& operator-(const RGBHex& x);
    Object_2d& operator*(const RGBHex& x);
    Object_2d& operator/(const RGBHex& x);
    //EREDITO QUESTI DALLA BASE VIRTUALI PURI
    //OVERRIDING
    //opertor di un oggetto a due dimensioni con un possibili oggetti a più dimensioni
    //Object_2d& operator+(const Space& x) const; //solleva eccezione non si può fare somma tra oggetti dimensionali diversi
    //Object_2d& operator-(const Space& x) const; //solleva eccezione non si può fare sottrazioni tra oggetti dimensionali diversi

    //conversioni lunghezza && altezza in cm e inch
    void setLCm(double l);
    double getLCm() const;
    void setLInch(double l);
    double getLInch() const;
    void setHCm(double h);
    double getHCm() const;
    void setHInch(double h);
    double getHInch() const;

};

#endif // OBJECT_2D_H
