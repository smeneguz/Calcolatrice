#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H
#include "object_1d.h"
#include "object_2d.h"
#include "object_3d.h"
#include "exceptions.h"
#include <vector>

class BusinessLogic{
private:
    std::vector<Object_1D*> monodimensionale;
    std::vector<Object_2d*> bidimensionale;
    std::vector<Object_3d*> tridimensionale;
    std::vector<RGBHex*> colori;
    Space* op1;
    Space* op2;
    Space* risultato;
    Space* selezione;
    int operatore;
    Object_1D risultato1D;
    Object_2d risultato2D;
    Object_3d risultato3D;
    RGBHex risultatoRGBHex;



public:
    BusinessLogic();
    Status getStatus(const Space& s) const;
    Space* getOp1() const;
    Space* getOp2() const;
    Space* getRisultato() const;
    Space* getSelezione() const;

    void newObj1D(int l, int risol);
    void newObj2D(int l, int h, int risol);
    void newObj3D(int l, int h, int d, int risol);
    void newColor(std::string c);

    Object_1D* getObj1D(int index);
    Object_2d* getObj2D(int index);
    Object_3d* getObj3D(int index);
    RGBHex* getRGBHex(int index);

};

#endif // BUSINESSLOGIC_H
