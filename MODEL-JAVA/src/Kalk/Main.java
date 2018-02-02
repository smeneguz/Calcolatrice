package Kalk;

public class Main{
public static void main(String [ ] args) throws Exceptions
{
	//creazione Object 
	BusinessLogic bu = new BusinessLogic();
	RGBHex colo = new RGBHex();
	Object_1D in1 = new Object_1D(1,3);
	Object_2D in2 = new Object_2D(6,3,3,colo);
	RGBHex colo2 = new RGBHex("000FF00");
	Object_3D in3 = new Object_3D(2, 2, 2, 2 ,colo2);
	RGBHex colo3 = new RGBHex("0001000");
	Object_2D in22 = new Object_2D(4,5,6,colo3);
	
	
	//settare Object su cui si vogliono fare i calcoli (esempio)
	ObjectO op1 = in2;
	ObjectO op2 = in22;
	
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
	//tutti tranne RGBHex hanno questo campo modificato in maniera opportuna
	System.out.println("Campo lunghezza : " + s.l);
	System.out.println("Campo lunghezza cm : " + s.lCm);
	
	//tutti tranne RGBHex e Object1D hanno questo campo modificato in maniera opportuna
	System.out.println("Campo altezza : " + s.h);
	System.out.println("Campo altezza cm : " + s.hCm);
	
	//solo Object3D ha questo campo
	System.out.println("Campo profondità : " + s.d);
	System.out.println("Campo profondità cm : " + s.dCm);
	
	//tutti gli object hanno questo campo
	System.out.println("Campo colore : " + s.color);


	

	

	

	 System.out.println("diooooooo");
}
}