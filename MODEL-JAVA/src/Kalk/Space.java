package Kalk;

public abstract class Space extends ObjectO {
	protected int dpi; //risoluzione di stampa
	protected RGBHex col; //colore di Space
	
	public Space() {
	    dpi = 72;
	    col = new RGBHex();
	}
	
	public Space(int d) {
	    dpi = d;
	    col = new RGBHex();
	}
	
	public Space(int d, RGBHex c) {
	    dpi = d;
	    col = c;
	}
	
	void setRisoluzione(int d)	{
	    dpi = d;
	}
	

	int getRisoluzione() {
		return dpi;
	}
	
	void setColor(RGBHex c)
	{
	    col = c;
	}
	
	RGBHex getColor() 
	{
	    return col;
	}
	
	public Status getStatus() 
	{
	    Status s = new Status();
	    s.dpi = this.getRisoluzione();
	    s.color = this.getColor().getColor(); //il ptimo mi ritorna un rgb e get color di rgb mi ritorna una stringa
	    return s;
	}
	
	//metodi astratti che verranno implementati nelle sotto classi
	//tra Space e RGBHex
	abstract Space sum (RGBHex x);
	abstract Space sub (RGBHex x);
	abstract Space mult (RGBHex x);
	abstract Space div (RGBHex x);
	
	//tra Space e Space
	abstract Space sum (Space x) throws Exceptions;
	abstract Space sub (Space x) throws Exceptions;
	abstract Space mult (Space x) throws Exceptions;
	abstract Space div (Space x) throws Exceptions;

}
