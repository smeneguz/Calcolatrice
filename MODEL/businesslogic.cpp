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
    Object_2D* o2 = new Object_2D(l, h, r);
    bidimensionale.push_back(o2);
}

void BusinessLogic::newObj3D(int l, int h, int d, int r)
{
    Object_3D* o3 = new Object_3D(l, h, d, r);
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

Object_2D *BusinessLogic::getObj2D(int index)
{
    Object_2D* o;
    std::vector<Object_2D*>::iterator it = bidimensionale.begin();
    bool trovato = false;
    for(int x=0; it < bidimensionale.end() && !trovato; x++, it++)
        if(x==index) {
            o = *it;
            trovato = true;
        }
    return o;
}

Object_3D *BusinessLogic::getObj3D(int index)
{
    Object_3D* o;
    std::vector<Object_3D*>::iterator it = tridimensionale.begin();
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

int BusinessLogic::getVectorSize(int i) const
{
    //bound index reference to specific contenitor
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    // 0 = monodimensionale, 1 = bidimensionale, 2 = tridimensionale, 3 = colori
    if (i == 0) return monodimensionale.size();
    if (i == 1) return bidimensionale.size();
    if(i == 2) return tridimensionale.size();
    //i == 3
    return colori.size();
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

void BusinessLogic::setOp1(Object *o)
{
    op1 = o;
}

void BusinessLogic::setOp2(Object *o)
{
    op2 = o;
}


void BusinessLogic::esegui()
{
    if(op1 && op2 && (operatore>=0)){ //verifico che siano stati inseriti i 2 dati su cui fare le operazioni e che l'operatore sia stato selezionato
    Object_1D* o11d = dynamic_cast<Object_1D*>(op1);
    Object_1D* o21d = dynamic_cast<Object_1D*>(op2);
    Object_2D* o12d = dynamic_cast<Object_2D*>(op1);
    Object_2D* o22d = dynamic_cast<Object_2D*>(op2);
    Object_3D* o13d = dynamic_cast<Object_3D*>(op1);
    Object_3D* o23d = dynamic_cast<Object_3D*>(op2);
    RGBHex* c1 = dynamic_cast<RGBHex*>(op1);
    RGBHex* c2 = dynamic_cast<RGBHex*>(op2);
    //adesso guardo tutti i casi, possibilità per ogni tipo che può essere op1 e op2

    if(o11d && c2){ // Obj1D op1   ?operatore?   RGBhex op2
        if(operatore==0){ //somma
            risultato1D = *o11d + *c2;
            risultato = &risultato1D;
        }

        else if(operatore==1){ //sottrazione
            risultato1D = *o11d - *c2;
            risultato = &risultato1D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato1D = *o11d * *c2;
            risultato = &risultato1D;
        }

        else if(operatore==3){ //divisione
            risultato1D = *o11d / *c2;
            risultato = &risultato1D;
        }
    }

    if(o11d && o21d){ //Obj1D op1   ?operatore?   Obj1D op2
        if(operatore==0){ //somma
            risultato1D = *o11d + *o21d;
            risultato = &risultato1D;
        }

        else if(operatore==1){ //sottrazione
            risultato1D = *o11d - *o21d;
            risultato = &risultato1D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato1D = *o11d * *o21d;
            risultato = &risultato1D;
        }

        else if(operatore==3){ //divisione
            risultato1D = *o11d / *o21d;
            risultato = &risultato1D;
        }
    }

    if(o11d && o22d){ //Obj1D op1   ?operatore?   Obj2D op2
        if(operatore==0){ //somma
            risultato1D = *o11d + *o22d;
            risultato = &risultato1D;
        }

        else if(operatore==1){ //sottrazione
            risultato1D = *o11d - *o22d;
            risultato = &risultato1D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato1D = *o11d * *o22d;
            risultato = &risultato1D;
        }

        else if(operatore==3){ //divisione
            risultato1D = *o11d / *o22d;
            risultato = &risultato1D;
        }
    }

    if(o11d && o23d){ //Obj1D op1   ?operatore?   Obj3D op2
        if(operatore==0){ //somma
            risultato1D = *o11d + *o23d;
            risultato = &risultato1D;
        }

        else if(operatore==1){ //sottrazione
            risultato1D = *o11d - *o23d;
            risultato = &risultato1D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato1D = *o11d * *o23d;
            risultato = &risultato1D;
        }

        else if(operatore==3){ //divisione
            risultato1D = *o11d / *o23d;
            risultato = &risultato1D;
        }
    }

    ////FINE 1D

    if(o12d && c2){ // Obj2D op1   ?operatore?   RGBhex op2
        if(operatore==0){ //somma
            risultato2D = *o12d + *c2;
            risultato = &risultato2D;
        }

        else if(operatore==1){ //sottrazione
            risultato2D = *o12d - *c2;
            risultato = &risultato2D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato2D = *o12d * *c2;
            risultato = &risultato2D;
        }

        else if(operatore==3){ //divisione
            risultato2D = *o12d / *c2;
            risultato = &risultato2D;
        }
    }

    if(o12d && o21d){ //Obj2D op1   ?operatore?   Obj1D op2
        if(operatore==0){ //somma
            risultato2D = *o12d + *o21d;
            risultato = &risultato2D;
        }

        else if(operatore==1){ //sottrazione
            risultato2D = *o12d - *o21d;
            risultato = &risultato2D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato2D = *o12d * *o21d;
            risultato = &risultato2D;
        }

        else if(operatore==3){ //divisione
            risultato2D = *o12d / *o21d;
            risultato = &risultato2D;
        }
    }

    if(o12d && o22d){ //Obj2D op1   ?operatore?   Obj2D op2
        if(operatore==0){ //somma
            risultato2D = *o12d + *o22d;
            risultato = &risultato2D;
        }

        else if(operatore==1){ //sottrazione
            risultato2D = *o12d - *o22d;
            risultato = &risultato2D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato2D = *o12d * *o22d;
            risultato = &risultato2D;
        }

        else if(operatore==3){ //divisione
            risultato2D = *o12d / *o22d;
            risultato = &risultato2D;
        }
    }

    if(o12d && o23d){ //Obj2D op1   ?operatore?   Obj3D op2
        if(operatore==0){ //somma
            risultato2D = *o12d + *o23d;
            risultato = &risultato2D;
        }

        else if(operatore==1){ //sottrazione
            risultato2D = *o12d - *o23d;
            risultato = &risultato2D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato2D = *o12d * *o23d;
            risultato = &risultato2D;
        }

        else if(operatore==3){ //divisione
            risultato2D = *o12d / *o23d;
            risultato = &risultato2D;
        }
    }
    //FINE 2D

    if(o13d && c2){ // Obj3D op1   ?operatore?   RGBhex op2
        if(operatore==0){ //somma
            risultato3D = *o13d + *c2;
            risultato = &risultato3D;
        }

        else if(operatore==1){ //sottrazione
            risultato3D = *o13d - *c2;
            risultato = &risultato3D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato3D = *o13d * *c2;
            risultato = &risultato3D;
        }

        else if(operatore==3){ //divisione
            risultato3D = *o13d / *c2;
            risultato = &risultato3D;
        }
    }

    if(o13d && o21d){ //Obj3D op1   ?operatore?   Obj1D op2
        if(operatore==0){ //somma
            risultato3D = *o13d + *o21d;
            risultato = &risultato3D;
        }

        else if(operatore==1){ //sottrazione
            risultato3D = *o13d - *o21d;
            risultato = &risultato3D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato3D = *o13d * *o21d;
            risultato = &risultato3D;
        }

        else if(operatore==3){ //divisione
            risultato3D = *o13d / *o21d;
            risultato = &risultato3D;
        }
    }

    if(o13d && o22d){ //Obj3D op1   ?operatore?   Obj2D op2
        if(operatore==0){ //somma
            risultato3D = *o13d + *o22d;
            risultato = &risultato3D;
        }

        else if(operatore==1){ //sottrazione
            risultato3D = *o13d - *o22d;
            risultato = &risultato3D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato3D = *o13d * *o22d;
            risultato = &risultato3D;
        }

        else if(operatore==3){ //divisione
            risultato3D = *o13d / *o22d;
            risultato = &risultato3D;
        }
    }

    if(o13d && o23d){ //Obj3D op1   ?operatore?   Obj3D op2
        if(operatore==0){ //somma
            risultato3D = *o13d + *o23d;
            risultato = &risultato3D;
        }

        else if(operatore==1){ //sottrazione
            risultato3D = *o13d - *o23d;
            risultato = &risultato3D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato3D = *o13d * *o23d;
            risultato = &risultato3D;
        }

        else if(operatore==3){ //divisione
            risultato3D = *o13d / *o23d;
            risultato = &risultato3D;
        }
    }
    //FINE 3D

    ////COLORE COME primo operatore ////
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
            risultato = &risultatoRGBHex;
        }
    }

    if(c1 && o21d){ // RGBHex op1   ?operatore?   Obj1D op2
        if(operatore==0){ //somma
            risultatoRGBHex = somma(*c1, *o21d);
            risultato = &risultatoRGBHex;
        }

        else if(operatore==1){ //sottrazione
            risultatoRGBHex = sottrazione(*c1, *o21d);
            risultato = &risultatoRGBHex;
        }

        else if(operatore==2){ //moltiplicazione
            risultatoRGBHex = moltiplicazione(*c1, *o21d);
            risultato = &risultatoRGBHex;
        }

        else if(operatore==3){ //divisione
            risultatoRGBHex = divisione(*c1, *o21d);
            risultato = & risultatoRGBHex;
        }

    }

    if(c1 && o22d){ //RGBHex op1   ?operatore?   Obj2D op2
        if(operatore==0){ // somma
            risultatoRGBHex = somma(*c1, *o22d);
            risultato = &risultatoRGBHex;
        }

        else if(operatore==1){ //sottrazione
            risultatoRGBHex = sottrazione(*c1, *o22d);
            risultato = &risultatoRGBHex;
        }

        else if(operatore==2){ //moltiplicazione
            risultatoRGBHex = moltiplicazione(*c1, *o22d);
            risultato = &risultatoRGBHex;
        }

        else if(operatore==3) //divisione
            risultatoRGBHex = divisione(*c1, *o22d);
            risultato = &risultatoRGBHex;
    }

    if(c1 && o23d){ //RGBHex op1   ?operatore?   Obj3D op2
        if(operatore==0){ //somma
            risultatoRGBHex = somma(*c1, *o23d);
            risultato = &risultatoRGBHex;
        }

        else if(operatore==1){ //sottrazione
            risultatoRGBHex = sottrazione(*c1, *o23d);
            risultato = &risultatoRGBHex;
        }

        else if(operatore==2){ //moltiplicazione
            risultatoRGBHex =  moltiplicazione(*c1, * o23d);
            risultato = &risultatoRGBHex;
        }

        else if(operatore==3){ // divisione
            risultatoRGBHex = divisione(*c1, *o23d);
            risultato = &risultatoRGBHex;
        }
    }
   }

}



void BusinessLogic::pulisci()
{
    op1 = 0;
    op2 = 0;
    risultato = 0;

}

bool BusinessLogic::saveResult() //salva il risultato delle operazioni nel vector del tipo giusto
{
    Object_1D* Obj1 = dynamic_cast<Object_1D*>(risultato);
    Object_2D* Obj2 = dynamic_cast<Object_2D*>(risultato);
    Object_3D* Obj3 = dynamic_cast<Object_3D*>(risultato);
    RGBHex* col = dynamic_cast<RGBHex*>(risultato);

    if(Obj1)
        monodimensionale.push_back(new Object_1D(Obj1->getLength(), Obj1->getRisoluzione(), Obj1->getColor()));
    else if(Obj2)
        bidimensionale.push_back(new Object_2D(Obj2->getLength(), Obj2->getHeight(), Obj2->getRisoluzione(), Obj2->getColor()));
    else if(Obj3)
        tridimensionale.push_back(new Object_3D(Obj3->getLength(), Obj3->getHeight(), Obj3->getDepth(), Obj3->getRisoluzione(), Obj3->getColor()));
    else if(col)
        colori.push_back(new RGBHex(col->getColor()));
    else return false;
    return true;
}

//funzioni statiche somma sottrazione tra rgb e classe derivante da space
RGBHex BusinessLogic::somma(RGBHex &c, Object_1D &o)
{
    RGBHex b;
    int val = c.getColorInt() + o.getColor().getColorInt();
    if (val>16777215) val=16777215;
    b.setColorInt(val);
    return b;
}

RGBHex BusinessLogic::sottrazione(RGBHex &c, Object_1D &o)
{
    RGBHex b;
    int val = c.getColorInt() - o.getColor().getColorInt();
    if(val<0) val=0;
    b.setColorInt(val);
    return b;
}

RGBHex BusinessLogic::moltiplicazione(RGBHex &, Object_1D /*&o*/)
{
    throw Ecc_RGBHex_moltiplicazione_Object();
}

RGBHex BusinessLogic::divisione(RGBHex& /*c */, Object_1D& /*o*/)
{
    throw Ecc_RGBHex_divisione_Object();
}

RGBHex BusinessLogic::somma(RGBHex &c, Object_2D &o)
{
    RGBHex b;
    int val = c.getColorInt() + o.getColor().getColorInt();
    if (val>16777215) val=16777215;
    b.setColorInt(val);
    return b;
}

RGBHex BusinessLogic::sottrazione(RGBHex &c, Object_2D &o)
{
    RGBHex b;
    int val = c.getColorInt() - o.getColor().getColorInt();
    if(val<0) val=0;
    b.setColorInt(val);
    return b;
}

RGBHex BusinessLogic::moltiplicazione(RGBHex &, Object_2D &)
{
     throw Ecc_RGBHex_moltiplicazione_Object();
}

RGBHex BusinessLogic::divisione(RGBHex &, Object_2D &)
{
    throw Ecc_RGBHex_divisione_Object();
}

RGBHex BusinessLogic::somma(RGBHex &c, Object_3D &o)
{
    RGBHex b;
    int val = c.getColorInt() + o.getColor().getColorInt();
    if (val>16777215) val=16777215;
    b.setColorInt(val);
    return b;
}

RGBHex BusinessLogic::sottrazione(RGBHex &c, Object_3D &o)
{
    RGBHex b;
    int val = c.getColorInt() - o.getColor().getColorInt();
    if(val<0) val=0;
    b.setColorInt(val);
    return b;
}

RGBHex BusinessLogic::moltiplicazione(RGBHex &, Object_3D &)
{
    throw Ecc_RGBHex_moltiplicazione_Object();
}

RGBHex BusinessLogic::divisione(RGBHex &, Object_3D &)
{
    throw Ecc_RGBHex_divisione_Object();
}
