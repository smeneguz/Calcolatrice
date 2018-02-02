package Kalk;

import java.util.Vector;

import javax.swing.text.html.HTMLDocument.Iterator;

public class BusinessLogic {
	private Vector<Object_1D> monodimensionale;
	private Vector<Object_2D> bidimensionale;
	private Vector<Object_3D> tridimensionale;
	private Vector<RGBHex> colori;
	private ObjectO op1;
	private ObjectO op2;
	private ObjectO risultato;
	private ObjectO selezione;
	private int operatore;
	private Object_1D risultato1D;
	private Object_2D risultato2D;
	private Object_3D risultato3D;
	private RGBHex risultatoRGBHex;
	
	public BusinessLogic() {
	    op1=null;
	    op2=null;
	    risultato=null;
	    operatore=-1; //nessuno
		
	}
	

Status getStatus(ObjectO o)
{
    return o.getStatus();
}

ObjectO getOp1() 
{
    return op1;
}

ObjectO getOp2() 
{
    return op2;
}

ObjectO getRisultato() 
{
    return risultato;
}

ObjectO getSelezione() 
{
    return selezione;
}
	
void newObj1D(int l, int r)
{
    Object_1D o1 = new Object_1D(l,r);
    monodimensionale.add(o1);
}

void newObj2D(int l, int h, int r)
{
    Object_2D o2 = new Object_2D(l, h, r);
    bidimensionale.add(o2);
}

void newObj3D(int l, int h, int d, int r)
{
    Object_3D o3 = new Object_3D(l, h, d, r);
    tridimensionale.add(o3);
}

void newColor(String c)
{
    RGBHex col = new RGBHex(c);
    colori.add(col);
}


Object_1D getObj1D(int index)
{
    Object_1D o=null;
    java.util.Iterator<Object_1D> it = monodimensionale.iterator();
   
    boolean trovato = false;
    for(int x=0; it.hasNext() && !trovato ; x++, it.next())
        if(x==index) {
            o = (Object_1D) it;
            trovato = true;
        }
    return o;
}

Object_2D getObj2D(int index)
{
    Object_2D o=null;
    java.util.Iterator<Object_2D> it = bidimensionale.iterator();
   
    boolean trovato = false;
    for(int x=0; it.hasNext() && !trovato ; x++, it.next())
        if(x==index) {
            o = (Object_2D) it;
            trovato = true;
        }
    return o;
}


Object_3D getObj3D(int index)
{
    Object_3D o=null;
    java.util.Iterator<Object_3D> it = tridimensionale.iterator();
   
    boolean trovato = false;
    for(int x=0; it.hasNext() && !trovato ; x++, it.next())
        if(x==index) {
            o = (Object_3D) it;
            trovato = true;
        }
    return o;
}


RGBHex getRGBHex(int index)
{
    RGBHex o=null;
    java.util.Iterator<RGBHex> it = colori.iterator();
   
    boolean trovato = false;
    for(int x=0; it.hasNext() && !trovato ; x++, it.next())
        if(x==index) {
            o = (RGBHex) it;
            trovato = true;
        }
    return o;
}



int getVectorSize(int i) 
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


void setOperator(int o)
{
    operatore = o;
}


void insertFirstSpace(ObjectO o)
{
    op1 = o;
}

void insertSecondSpace(ObjectO o)
{
    op2 = o;
}

void setSelezione(ObjectO o)
{
    selezione = o;
}

void setOp1(ObjectO o)
{
    op1 = o;
}

void setOp2(ObjectO o)
{
    op2 = o;
}

void pulisci()
{
    op1 = null;
    op2 = null;
    risultato = null;

}

void esegui() throws Exceptions
{
	Object_1D o11d = null;
	Object_1D o21d = null;
	Object_2D o12d = null;
	Object_2D o22d = null;
	Object_3D o13d = null;
	Object_3D o23d = null;
	RGBHex c1 = null;
	RGBHex c2 = null;
    if((op1 != null) && (op2 != null) && (operatore>=0)){ //verifico che siano stati inseriti i 2 dati su cui fare le operazioni e che l'operatore sia stato selezionato
    if(op1 instanceof Object_1D ) o11d = (Object_1D) op1;
    if(op2 instanceof Object_1D ) o21d = (Object_1D) op2 ;
    if(op1 instanceof Object_2D ) o12d = (Object_2D)(op1);
    if(op2 instanceof Object_2D ) o22d = (Object_2D)(op2);
    if(op1 instanceof Object_3D ) o13d = (Object_3D)(op1);
    if(op2 instanceof Object_3D ) o23d = (Object_3D)(op2);
    if(op1 instanceof RGBHex ) c1 = (RGBHex)(op1);
    if(op2 instanceof RGBHex ) c2 = (RGBHex)(op2);
    //adesso guardo tutti i casi, possibilità per ogni tipo che può essere op1 e op2

    if(o11d != null && c2 != null){ // Obj1D op1   ?operatore?   RGBhex op2
        if(operatore==0){ //somma
            risultato1D = o11d.sum(c2);
            risultato = risultato1D;
        }

        else if(operatore==1){ //sottrazione
            risultato1D = o11d.sub(c2);
            risultato = risultato1D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato1D = o11d.mult(c2);
            risultato = risultato1D;
        }

        else if(operatore==3){ //divisione
            risultato1D = o11d.div(c2);
            risultato = risultato1D;
        }
    }

    if(o11d != null && o21d!= null){ //Obj1D op1   ?operatore?   Obj1D op2
        if(operatore==0){ //somma
            risultato1D = o11d.sum(o21d);
            risultato = risultato1D;
        }

        else if(operatore==1){ //sottrazione
            risultato1D = o11d.sub(o21d);
            risultato = risultato1D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato1D = o11d.mult(o21d);
            risultato = risultato1D;
        }

        else if(operatore==3){ //divisione
            risultato1D = o11d.div(o21d);
            risultato = risultato1D;
        }
    }

    if(o11d != null && o22d != null){ //Obj1D op1   ?operatore?   Obj2D op2
        if(operatore==0){ //somma
            risultato1D = o11d.sum(o22d);
            risultato = risultato1D;
        }

        else if(operatore==1){ //sottrazione
            risultato1D = o11d.sub(o22d);
            risultato = risultato1D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato1D = o11d.mult(o22d);
            risultato = risultato1D;
        }

        else if(operatore==3){ //divisione
            risultato1D = o11d.div(o22d);
            risultato = risultato1D;
        }
    }

    if(o11d != null && o23d != null){ //Obj1D op1   ?operatore?   Obj3D op2
        if(operatore==0){ //somma
            risultato1D = o11d.sum(o23d);
            risultato = risultato1D;
        }

        else if(operatore==1){ //sottrazione
            risultato1D = o11d.sub(o23d);
            risultato = risultato1D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato1D = o11d.mult(o23d);
            risultato = risultato1D;
        }

        else if(operatore==3){ //divisione
            risultato1D = o11d.div(o23d);
            risultato = risultato1D;
        }
    }

    ////FINE 1D

    if(o12d != null && c2 != null){ // Obj2D op1   ?operatore?   RGBhex op2
        if(operatore==0){ //somma
            risultato2D = o12d.sum(c2);
            risultato = risultato2D;
        }

        else if(operatore==1){ //sottrazione
            risultato2D = o12d.sub(c2);
            risultato = risultato2D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato2D = o12d.mult(c2);
            risultato = risultato2D;
        }

        else if(operatore==3){ //divisione
            risultato2D = o12d.div(c2);
            risultato = risultato2D;
        }
    }

    if(o12d != null && o21d != null){ //Obj2D op1   ?operatore?   Obj1D op2
        if(operatore==0){ //somma
            risultato2D = o12d.sum(o21d);
            risultato = risultato2D;
        }

        else if(operatore==1){ //sottrazione
            risultato2D = o12d.sub(o21d);
            risultato = risultato2D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato2D = o12d.mult(o21d);
            risultato = risultato2D;
        }

        else if(operatore==3){ //divisione
            risultato2D = o12d.div(o21d);
            risultato = risultato2D;
        }
    }

    if(o12d != null && o22d != null){ //Obj2D op1   ?operatore?   Obj2D op2
        if(operatore==0){ //somma
            risultato2D = o12d.sum(o22d);
            risultato = risultato2D;
        }

        else if(operatore==1){ //sottrazione
            risultato2D = o12d.sub(o22d);
            risultato = risultato2D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato2D = o12d.mult(o22d);
            risultato = risultato2D;
        }

        else if(operatore==3){ //divisione
            risultato2D = o12d.div(o22d);
            risultato = risultato2D;
        }
    }

    if(o12d != null && o23d != null){ //Obj2D op1   ?operatore?   Obj3D op2
        if(operatore==0){ //somma
            risultato2D = o12d.sum(o23d);
            risultato = risultato2D;
        }

        else if(operatore==1){ //sottrazione
            risultato2D = o12d.sub(o23d);
            risultato = risultato2D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato2D = o12d.mult(o23d);
            risultato = risultato2D;
        }

        else if(operatore==3){ //divisione
            risultato2D = o12d.div(o23d);
            risultato = risultato2D;
        }
    }
    //FINE 2D

    if(o13d != null && c2 != null){ // Obj3D op1   ?operatore?   RGBhex op2
        if(operatore==0){ //somma
            risultato3D = o13d.sum(c2);
            risultato = risultato3D;
        }

        else if(operatore==1){ //sottrazione
            risultato3D = o13d.sub(c2);
            risultato = risultato3D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato3D = o13d.mult(c2);
            risultato = risultato3D;
        }

        else if(operatore==3){ //divisione
            risultato3D = o13d.div(c2);
            risultato = risultato3D;
        }
    }

    if(o13d != null && o21d != null){ //Obj3D op1   ?operatore?   Obj1D op2
        if(operatore==0){ //somma
            risultato3D = o13d.sum(o21d);
            risultato = risultato3D;
        }

        else if(operatore==1){ //sottrazione
            risultato3D = o13d.sub(o21d);
            risultato = risultato3D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato3D = o13d.mult(o21d);
            risultato = risultato3D;
        }

        else if(operatore==3){ //divisione
            risultato3D = o13d.div(o21d);
            risultato = risultato3D;
        }
    }

    if(o13d != null && o22d != null){ //Obj3D op1   ?operatore?   Obj2D op2
        if(operatore==0){ //somma
            risultato3D = o13d.sum(o22d);
            risultato = risultato3D;
        }

        else if(operatore==1){ //sottrazione
            risultato3D = o13d.sub(o22d);
            risultato = risultato3D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato3D = o13d.mult(o22d);
            risultato = risultato3D;
        }

        else if(operatore==3){ //divisione
            risultato3D = o13d.div(o22d);
            risultato = risultato3D;
        }
    }

    if(o13d != null && o23d != null  ){ //Obj3D op1   ?operatore?   Obj3D op2
        if(operatore==0){ //somma
            risultato3D = o13d.sum(o23d);
            risultato = risultato3D;
        }

        else if(operatore==1){ //sottrazione
            risultato3D = o13d.sub(o23d);
            risultato = risultato3D;
        }

        else if(operatore==2){ //moltiplicazione
            risultato3D = o13d.mult(o23d);
            risultato = risultato3D;
        }

        else if(operatore==3){ //divisione
            risultato3D = o13d.div(o23d);
            risultato = risultato3D;
        }
    }
    //FINE 3D

    ////COLORE COME primo operatore ////
    //RGBHex op1   ?operatore?   RGBHex op2
    if(c1 != null && c2 != null){
        if(operatore==0){ //somma
            risultatoRGBHex = c1.sum(c2);
            risultato = risultatoRGBHex;
        }

        else if(operatore==1){ //sottrazione
            risultatoRGBHex = c1.sub(c2);
            risultato = risultatoRGBHex;
        }

        else if(operatore==2){ //moltiplicazione
            risultatoRGBHex = c1.mult(c2);
            risultato = risultatoRGBHex;
        }

        else if(operatore==3){ // divisione
            risultatoRGBHex = c1.div(c2);
            risultato = risultatoRGBHex;
        }
    }

    if(c1 != null && o21d != null){ // RGBHex op1   ?operatore?   Obj1D op2
        if(operatore==0){ //somma
            risultatoRGBHex = somma(c1, o21d);
            risultato = risultatoRGBHex;
        }

        else if(operatore==1){ //sottrazione
            risultatoRGBHex = sottrazione(c1, o21d);
            risultato = risultatoRGBHex;
        }

        else if(operatore==2){ //moltiplicazione
            risultatoRGBHex = moltiplicazione(c1, o21d);
            risultato = risultatoRGBHex;
        }

        else if(operatore==3){ //divisione
            risultatoRGBHex = divisione(c1, o21d);
            risultato =  risultatoRGBHex;
        }

    }

    if(c1 != null && o22d != null){ //RGBHex op1   ?operatore?   Obj2D op2
        if(operatore==0){ // somma
            risultatoRGBHex = somma(c1, o22d);
            risultato = risultatoRGBHex;
        }

        else if(operatore==1){ //sottrazione
            risultatoRGBHex = sottrazione(c1, o22d);
            risultato = risultatoRGBHex;
        }

        else if(operatore==2){ //moltiplicazione
            risultatoRGBHex = moltiplicazione(c1, o22d);
            risultato = risultatoRGBHex;
        }

        else if(operatore==3) //divisione
            risultatoRGBHex = divisione(c1, o22d);
            risultato = risultatoRGBHex;
    }

    if(c1 != null && o23d != null){ //RGBHex op1   ?operatore?   Obj3D op2
        if(operatore==0){ //somma
            risultatoRGBHex = somma(c1, o23d);
            risultato = risultatoRGBHex;
        }

        else if(operatore==1){ //sottrazione
            risultatoRGBHex = sottrazione(c1, o23d);
            risultato = risultatoRGBHex;
        }

        else if(operatore==2){ //moltiplicazione
            risultatoRGBHex =  moltiplicazione(c1,  o23d);
            risultato = risultatoRGBHex;
        }

        else if(operatore==3){ // divisione
            risultatoRGBHex = divisione(c1, o23d);
            risultato = risultatoRGBHex;
        }
    }
   }

}

boolean saveResult() //salva il risultato delle operazioni nel vector del tipo giusto
{
	Object_1D Obj1 = null;
	Object_2D Obj2 = null;
	Object_3D Obj3 = null;
	RGBHex col = null;
    if (risultato instanceof Object_1D) Obj1 = (Object_1D)(risultato);
    if (risultato instanceof Object_2D)Obj2 = (Object_2D)(risultato);
    if (risultato instanceof Object_3D) Obj3 = (Object_3D)(risultato);
    if (risultato instanceof RGBHex) col = (RGBHex)(risultato);

    if(Obj1 != null)
        monodimensionale.add(new Object_1D(Obj1.getLength(), Obj1.getRisoluzione(), Obj1.getColor()));
    else if(Obj2 != null)
        bidimensionale.add(new Object_2D(Obj2.getLength(), Obj2.getHeight(), Obj2.getRisoluzione(), Obj2.getColor()));
    else if(Obj3 != null)
        tridimensionale.add(new Object_3D(Obj3.getLength(), Obj3.getHeight(), Obj3.getDepth(), Obj3.getRisoluzione(), Obj3.getColor()));
    else if(col != null)
        colori.add(new RGBHex(col.getColor()));
    else return false;
    return true;
}


static RGBHex divisione(RGBHex c1, Object_3D o23d) throws Exceptions {
	throw new Exceptions("RGBHex non può essere divisa con un oggetto");

}


static RGBHex moltiplicazione(RGBHex c1, Object_3D o23d) throws Exceptions{
	throw new Exceptions("RGBHex non può essere moltiplicato con un oggetto");

}


static RGBHex sottrazione(RGBHex c, Object_3D o) {
    RGBHex b = new RGBHex();
    int val = c.getColorInt() - o.getColor().getColorInt();
    if(val<0) val=0;
    b.setColorInt(val);
    return b;
}


static RGBHex somma(RGBHex c, Object_3D o) {
    RGBHex b = new RGBHex();
    int val = c.getColorInt() + o.getColor().getColorInt();
    if (val>16777215) val=16777215;
    b.setColorInt(val);
    return b;
}


static RGBHex divisione(RGBHex c1, Object_2D o22d) throws Exceptions  {
	throw new Exceptions("RGBHex non può essere divisa con un oggetto");

}


static RGBHex moltiplicazione(RGBHex c1, Object_2D o) throws Exceptions  {
	throw new Exceptions("RGBHex non può essere moltiplicata con un oggetto");
}


static RGBHex sottrazione(RGBHex c, Object_2D o) {
    RGBHex b = new RGBHex();
    int val = c.getColorInt() - o.getColor().getColorInt();
    if(val<0) val=0;
    b.setColorInt(val);
    return b;
}


static RGBHex somma(RGBHex c, Object_2D o) {
    RGBHex b = new RGBHex();
    int val = c.getColorInt() + o.getColor().getColorInt();
    if (val>16777215) val=16777215;
    b.setColorInt(val);
    return b;
}


static RGBHex divisione(RGBHex c1, Object_1D o21d) throws Exceptions  {
	throw new Exceptions("RGBHex non può essere divisa con un oggetto");

}


static RGBHex moltiplicazione(RGBHex c1, Object_1D o21d) throws Exceptions {

	throw new Exceptions("RGBHex non può essere moltiplicato con un oggetto");
}


static RGBHex sottrazione(RGBHex c, Object_1D o) {
    RGBHex b = new RGBHex();
    int val = c.getColorInt() - o.getColor().getColorInt();
    if(val<0) val=0;
    b.setColorInt(val);
    return b;
}


static RGBHex somma(RGBHex c, Object_1D o) {
    RGBHex b = new RGBHex();
    int val = c.getColorInt() + o.getColor().getColorInt();
    if (val>16777215) val=16777215;
    b.setColorInt(val);
    return b;
}

}
