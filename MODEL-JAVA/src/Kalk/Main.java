package Kalk;

public class Main{
public static void main(String [ ] args) throws Exceptions
{
	//creazione Object 
	int r = 456;
	int g =567;
	int b =22;
	
	RGBHex colo1 = new RGBHex(r,g,b);
	
	int r2 = 1;
	int g2 = 2;
	int b2 = 3;
	
	RGBHex colo2 = new RGBHex(r2, g2, b2);
	
	BusinessLogic bu = new BusinessLogic();
	RGBHex colo = new RGBHex();
	Object_1D in1 = new Object_1D(1,3);
	Object_2D in2 = new Object_2D(6,3,3,colo2);
	RGBHex colo3 = new RGBHex("FFFFFF");
	Object_3D in3 = new Object_3D(2, 2, 2, 2 ,colo1);
	Object_2D in22 = new Object_2D(4,5,6,colo);
	Object_3D in32 = new Object_3D(5, 5, 5, 5 ,colo);
	
	
	
	//settare Object su cui si vogliono fare i calcoli (esempio)
	ObjectO op1 = colo1;
	ObjectO op2 = in2;
	
	//esempio per far vedere colore - Object2D
	//settare gli operatori della BusinessLogic
	bu.setOp1(op1);
	bu.setOp2(op2);
	
	//set tipo di operazione   somma == 0    sottrazione == 1    moltiplicazione ==2    divisione == 3
	bu.setOperator(1);
	
	// blocco di esecuzione del calcolo inserito in un blocco try pochè può sollevare eccezioni
	try {
	bu.esegui();
	}
	catch(Exceptions a) { System.out.println(a.getErr());}
	

	
	//mi ricavo tutte le informazioni riguardante all'object risultante dall'operazione contenute nel suo status
	Status s = bu.getRisultato().getStatus();
	
	//tutti gli object hanno questo campo
	System.out.println("Campo colore : " + s.color);	
	
	//tutti tranne RGBHex hanno questo campo modificato in maniera opportuna
	System.out.println("Campo lunghezza : " + s.l);
	System.out.println("Campo lunghezza cm : " + s.lCm);
	
	//tutti tranne RGBHex e Object1D hanno questo campo modificato in maniera opportuna
	System.out.println("Campo altezza : " + s.h);
	System.out.println("Campo altezza cm : " + s.hCm);
	
	//solo Object3D ha questo campo
	System.out.println("Campo profondità : " + s.d);
	System.out.println("Campo profondità cm : " + s.dCm);
	
	
	///////////////////////////fine primo esempio (stampa)
	System.out.println("fine prima stampa/esempio //////////////////////");
	
	
	//secondo esempio
	
	ObjectO op3 = in3;
	ObjectO op4 = in32;
	
	//esempio per far vedere colore - Object2D
	//settare gli operatori della BusinessLogic
	bu.setOp1(op3);
	bu.setOp2(op4);
	
	//set tipo di operazione   somma == 0    sottrazione == 1    moltiplicazione ==2    divisione == 3
	bu.setOperator(0);
	
	// blocco di esecuzione del calcolo inserito in un blocco try pochè può sollevare eccezioni
	try {
	bu.esegui();
	}
	catch(Exceptions a) { System.out.println(a.getErr());}
	

	
	//mi ricavo tutte le informazioni riguardante all'object risultante dall'operazione contenute nel suo status
	Status s1 = bu.getRisultato().getStatus();
	
	//tutti gli object hanno questo campo
	System.out.println("Campo colore : " + s1.color);	
	
	//tutti tranne RGBHex hanno questo campo modificato in maniera opportuna
	System.out.println("Campo lunghezza : " + s1.l);
	System.out.println("Campo lunghezza cm : " + s1.lCm);
	
	//tutti tranne RGBHex e Object1D hanno questo campo modificato in maniera opportuna
	System.out.println("Campo altezza : " + s1.h);
	System.out.println("Campo altezza cm : " + s1.hCm);
	
	//solo Object3D ha questo campo
	System.out.println("Campo profondità : " + s1.d);
	System.out.println("Campo profondità cm : " + s1.dCm);
	


}
}