#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H
#include "object_1d.h"
#include "object_2d.h"
#include "object_3d.h"
#include <vector>

class BusinessLogic{
private:
    std::vector<Object_1D*> monodimensionale;
    std::vector<Object_2d*> bidimensionale;
    std::vector<Object_3d*> tridimensionale;
    std::vector<RGBHex*> colori;
    Object* op1;
    Object* op2;
    Object* risultato;
    Object* selezione;
    int operatore;
    Object_1D risultato1D;
    Object_2d risultato2D;
    Object_3d risultato3D;
    RGBHex risultatoRGBHex;



public:
    BusinessLogic();
    Status getStatus(const Object& o) const;
    Object* getOp1() const;
    Object* getOp2() const;
    Object* getRisultato() const;
    Object* getSelezione() const;

    void newObj1D(int l, int r);
    void newObj2D(int l, int h, int r);
    void newObj3D(int l, int h, int d, int r);
    void newColor(std::string c);

    Object_1D* getObj1D(int index);
    Object_2d* getObj2D(int index);
    Object_3d* getObj3D(int index);
    RGBHex* getRGBHex(int index);

    //scegliere operatore 0 = somma, 1 = sottrazione, 2 = moltiplicazione, 3 = divisione
    void setOperator(int o);

    void insertFirstSpace(Object* o);
    void insertSecondSpace(Object* o);

    void setSelezione(Object* o);
    void setOp1(Object* o);
    void setOp2(Object* o);

    void esegui();
    void pulisci();
    bool saveResult();

};

#endif // BUSINESSLOGIC_H
