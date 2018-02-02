package Kalk;

public class Object_1D extends Space {
	private int length;
	
	//Costruttori
	public Object_1D() {
		super();
		length=1;
	}
	
	public Object_1D(int l) {
		super();
		length=l;
	}
	
	public Object_1D(int l, int risol) {
		super(risol);
		length=l;	
	}
	
	public Object_1D(int l, int risol, RGBHex c) {
		super(risol, c);
		length=l;
	}
	
	public Status getStatus() 
	{
	    Status s = super.getStatus();
	    //sistemare lunghezza
	    s.l = this.getLength();
	    s.lCm = this.getLCm();
	    s.lInch = this.getLInch();
	    return s;
	}

	private double getLInch() {

	    double a = (double)length;
	    double b = (double)length;
	    return (a/b);
	}

	private double getLCm() {
	    double a = (double)length;
	    double b = (double)dpi;
	    return ((a/b)*2.54);
	}

	int getLength() {
		return length;
	}
	

	void setLength(int l)
		{
			length = l;
		}

	void setLInch(double l) {
    		length = (int) (dpi*l);
    		if ((dpi*l)-length > 0) length++; // Arrotondo per eccesso
		}
	
	void setLCm(double l) {
	    length = (int) (dpi*(l/2.54)); // l/2.54 serve per convertire la lunghezza l da cm a pollici
	    if ((dpi*(l/2.54))-length > 0) length++; // Arrotondo per eccesso
	}


	//Object_1D con RGBHex
	
	@Override
	Object_1D sum(RGBHex x)  {
	    RGBHex b = new RGBHex();
	    int val = x.getColorInt() + this.col.getColorInt();
	    if (val>16777215) val=16777215;
	    b.setColorInt(val);
	    this.setColor(b);
	    
	    return this;
	}

	@Override
	Object_1D sub(RGBHex x) {
	    RGBHex b = new RGBHex();
	    int val = col.getColorInt() - x.getColorInt();
	    if(val<0) val=0;
	    b.setColorInt(val);
	    this.setColor(b);
	    return this;
	}

	@Override
	Object_1D mult(RGBHex x) {
	    this.setColor(col);
	    return this;
	}

	@Override
	Object_1D div(RGBHex x) {
	    if(col.getColorInt() == (x.getColorInt()))
	    this.setColor(new RGBHex("000000"));
	    else
	    	this.setColor(col);
	    return this;
	}
	
	//Object_1D con Space

	@Override
	Object_1D sum(Space x) throws Exceptions{
	    if(x instanceof Object_1D)
	    {
	    	Object_1D a = (Object_1D) x;
	        int val = this.getLength() + a.getLength();
	        this.setLength(val);
	        this.setRisoluzione(a.getRisoluzione()); //la somma ritorna semplicemente la risoluzione del parametro passato
	        super.col = super.col.sum( x.col);
	        return this;
	    }
	    //non fa niente in questo caso se non è del tipo giusto
	    throw new Exceptions("Object1D non può sommarsi con tipi diversi di space da esso");
	}

	@Override
	Object_1D sub(Space x) throws Exceptions{
	    if(x instanceof Object_1D)
	    {
	    	Object_1D a = (Object_1D) x;
	        int val = this.getLength() - a.getLength();
	        if(val <=0) val = 1;
	        this.setLength(val);
	        this.setRisoluzione(a.getRisoluzione()); //la sottrazione ritorna semplicemente la risoluzione del parametro passato
	        super.col = super.col.sub( x.col);
	        return this;
	    }
	    throw new Exceptions("Object1D non può sottrarsi con tipi diversi di space da esso");
	}

	@Override
	Object_1D mult(Space x) throws Exceptions {
	    if(x instanceof Object_1D)
	    {
	    	Object_1D a = (Object_1D) x;
	        int val = this.getLength() * a.getLength();
	        this.setLength(val);
	        this.setRisoluzione(a.getRisoluzione()); //la moltiplicazione ritorna semplicemente la risoluzione del parametro passato
	        super.col = super.col.sum( x.col);
	        return this;
	    }
	    throw new Exceptions("Object1D non può moltiplicarsi con tipi diversi di space da esso");
	}

	@Override
	Object_1D div(Space x) throws Exceptions {
	    if(x instanceof Object_1D)
	    {
	    	Object_1D a = (Object_1D) x;
	        int val = this.getLength() / a.getLength();
	        if(val <=0) val = 1;
	        this.setLength(val);
	        this.setRisoluzione(a.getRisoluzione()); //la moltiplicazione ritorna semplicemente la risoluzione del parametro passato
	        super.col = super.col.sub( x.col);
	        return this;
	    }

	    throw new Exceptions("Object1D non può dividersi con tipi diversi di space da esso");
	}

}
