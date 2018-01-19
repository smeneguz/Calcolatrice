#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H
#include "object_1d.h"
#include "object_2d.h"
#include "object_3d.h"
#include <vector>
#include <iostream>

class BusinessLogic{
private:
    std::vector<Object_1D*> monodimensionale;
    std::vector<Object_2D*> bidimensionale;
    std::vector<Object_3D*> tridimensionale;
    std::vector<RGBHex*> colori;
    Object* op1;
    Object* op2;
    Object* risultato;
    Object* selezione;
    int operatore;
    Object_1D risultato1D;
    Object_2D risultato2D;
    Object_3D risultato3D;
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
    Object_2D* getObj2D(int index);
    Object_3D* getObj3D(int index);
    RGBHex* getRGBHex(int index);
    int getVectorSize(int i) const;

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

    //funzioni statiche in cui il primo membro dell'operazione sia un colore
    //le posiziono qua per evitare #include nella classe RGBhex che porrterebbe a degli include ciclici

    // RGBHex && oggetto1D
    static RGBHex somma(RGBHex& c, Object_1D& o);
    static RGBHex sottrazione(RGBHex& c, Object_1D& o);
    static RGBHex moltiplicazione(RGBHex& , Object_1D& o);
    static RGBHex divisione(RGBHex&, Object_1D&);

    // RGBHex && oggetto2D
    static RGBHex somma(RGBHex& c, Object_2D& o);
    static RGBHex sottrazione(RGBHex& c, Object_2D& o);
    static RGBHex moltiplicazione(RGBHex& , Object_2D& o);
    static RGBHex divisione(RGBHex& , Object_2D& );

    // RGBHex && oggetto3D
    static RGBHex somma(RGBHex& c, Object_3D& o);
    static RGBHex sottrazione(RGBHex& c, Object_3D& o);
    static RGBHex moltiplicazione(RGBHex&, Object_3D& o);
    static RGBHex divisione(RGBHex& , Object_3D& );

};

#endif // BUSINESSLOGIC_H
