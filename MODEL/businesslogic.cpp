#include "businesslogic.h"

BusinessLogic::BusinessLogic() {
    op1=0;
    op2=0;
    risultato=0;
    operatore=-1; //nessuno
}

Status BusinessLogic::getStatus(const Object &o) const
{
    return o.getStatus();
}

Object *BusinessLogic::getOp1() const
{
    return op1;
}

Object *BusinessLogic::getOp2() const
{
    return op2;
}

Object *BusinessLogic::getRisultato() const
{
    return risultato;
}

Object *BusinessLogic::getSelezione() const
{
    return selezione;
}

void BusinessLogic::newObj1D(int l, int r)
{
    Object_1D* o1 = new Object_1D(l,r);
    monodimensionale.push_back(o1);
}

void BusinessLogic::newObj2D(int l, int h, int r)
{
    Object_2d* o2 = new Object_2d(l, h, r);
    bidimensionale.push_back(o2);
}

void BusinessLogic::newObj3D(int l, int h, int d, int r)
{
    Object_3d* o3 = new Object_3d(l, h, d, r);
    tridimensionale.push_back(o3);
}

void BusinessLogic::newColor(std::string c)
{
    RGBHex* col = new RGBHex(c);
    colori.push_back(col);
}

Object_1D *BusinessLogic::getObj1D(int index)
{
    Object_1D* o;
    std::vector<Object_1D*>::iterator it = monodimensionale.begin();
    bool trovato = false;
    for(int x=0; it < monodimensionale.end() && !trovato ; x++, it++)
        if(x==index) {
            o = *it;
            trovato = true;
        }
    return o;
}

Object_2d *BusinessLogic::getObj2D(int index)
{
    Object_2d* o;
    std::vector<Object_2d*>::iterator it = bidimensionale.begin();
    bool trovato = false;
    for(int x=0; it < bidimensionale.end() && !trovato; x++, it++)
        if(x==index) {
            o = *it;
            trovato = true;
        }
    return o;
}

Object_3d *BusinessLogic::getObj3D(int index)
{
    Object_3d* o;
    std::vector<Object_3d*>::iterator it = tridimensionale.begin();
    bool trovato = false;
    for(int x=0; it < tridimensionale.end() && !trovato; x++, it++)
        if(x==index) {
            o = *it;
            trovato = true;
        }
    return o;
}

RGBHex *BusinessLogic::getRGBHex(int index)
{
    RGBHex* o;
    std::vector<RGBHex*>::iterator it = colori.begin();
    bool trovato = false;
    for(int x=0; it < colori.end() && !trovato; x++, it++)
        if(x==index) {
            o = *it;
            trovato = true;
        }
    return o;
}

void BusinessLogic::setOperator(int o)
{
    operatore = o;
}

void BusinessLogic::insertFirstSpace(Object *o)
{
    op1 = o;
}

void BusinessLogic::insertSecondSpace(Object *o)
{
    op2 = o;
}

void BusinessLogic::setSelezione(Object *o)
{
    selezione = o;
}

void BusinessLogic::setOp1(Object *o) //si ripettono da vedere se serve
{
    op1 = o;
}

void BusinessLogic::setOp2(Object *o) //si ripettono da vedere se serve
{
    op2 = o;
}

void BusinessLogic::esegui()
{
    if(op1 && op2 && (operatore>=0)){ //verifico che siano stati inseriti i 2 dati su cui fare le operazioni e che l'operatore sia stato selezionato
    Object_1D* o11d = dynamic_cast<Object_1D*>(op1);
    Object_1D* o21d = dynamic_cast<Object_1D*>(op2);
    Object_2d* o12d = dynamic_cast<Object_2d*>(op1);
    Object_2d* o22d = dynamic_cast<Object_2d*>(op2);
    Object_3d* o13d = dynamic_cast<Object_3d*>(op1);
    Object_3d* o23d = dynamic_cast<Object_3d*>(op2);
    RGBHex* c1 = dynamic_cast<RGBHex*>(op1);
    RGBHex* c2 = dynamic_cast<RGBHex*>(op2);
    //adesso guardo tutti i casi, possibilità per ogni tipo che può essere op1 e op2

    //RGBHex op1   ?operatore?   RGBHex op2
    if(c1 && c2){
        if(operatore==0){ //somma
            risultatoRGBHex = *c1 + *c2;
            risultato = &risultatoRGBHex;
        }

        else if(operatore==1){ //sottrazione
            risultatoRGBHex = *c1 - *c2;
            risultato = &risultatoRGBHex;
        }

        else if(operatore==2){ //moltiplicazione
            risultatoRGBHex = *c1 * *c2;
            risultato = &risultatoRGBHex;
        }

        else if(operatore==3){ // divisione
            risultatoRGBHex = *c1 / *c2;
            risultato = risultatoRGBHex;
        }
    }

    if(c1 && o21d){ // RGBHex op1   ?operatore?   Obj1D op2
        if(operatore==0){

        }
    }
    }

}

void BusinessLogic::pulisci()
{

}

bool BusinessLogic::saveResult()
{

}
