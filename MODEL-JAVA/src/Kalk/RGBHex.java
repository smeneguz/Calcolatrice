package Kalk;

public class RGBHex extends ObjectO {
	private int color = 0;
	private static final char c[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	private static String pulisciS (String s, int n) {
		String inputM = s;
		String input = "";
		String charP = null;
		String suffisso="";
		for(int i=0; i<n; i++) suffisso += "0";
		 for (int i=(inputM.length()-1); i>=0; i--) {
		        charP += inputM.charAt(i); // append char to string
		        if ((charP.compareTo("9")<=0 && charP.compareTo("0")>=0) ||
		            (charP.compareTo("f")<=0 && charP.compareTo("a")>=0) ||
		            (charP.compareTo("F")<=0 && charP.compareTo("A")>=0)) {
		            // Se charP è compreso fra 'a' e 'f' lo metto maiuscolo, sottraendo 32 posizioni della tabella ASCII
		            if ((charP.compareTo("f")<=0 && charP.compareTo("a")>=0)) charP = charP.substring(charP.charAt(0)-32); //valueOf(charP.charAt(0)-32);
		            input = ""+charP+input;
		        }
		    }
		    input = suffisso+input;
		    input = input.substring(input.length()-n,n);
		    return input;
	}
	
	private static int valoreS(String c, int n) {
		String s = pulisciS(c,n);
		String charP = null;
		int colore = 0;
		int val;
	    for (int i=0; i<n; i++) {
	        charP += s.charAt((n-1)-i); //[(n-1)-i];
	        if ((charP.compareTo("9")<=0 && charP.compareTo("0")>=0)) val = 0+charP.charAt(0)-48;
	        else val = 10+charP.charAt(0)-65;
	        colore += val*((int)(Math.pow(16,i)));
	    }
		
		return colore;
	}
	
	//costruttori
	public RGBHex() {
		this.color = 0;
	}
	public RGBHex(String c) {
		this.color = valoreS(c,6);
	}
	public RGBHex(int r, int g, int b) {
	    if (r<0) r=0;
	    if (r>255) r=255;
	    if (g<0) g=0;
	    if (g>255) g=255;
	    if (b<0) g=0;
	    if (b>255) g=255;
	    int c = b + g*256 + r*65536;
	    this.color = c;
	}
	
	//funzioni set e get
    void setColor(String c) {
    	color = valoreS(c,6);
    }
	
    void setColorInt(int c) {
    	color = c;
        if (c>16777215) color = 16777215;
        else if (c<0) color = 0;
	}
    final String getColor() {
        String output = "";
        int x = color;
        int y = x;
        int div = 1048576;
        for (int i=0; i<6; i++) {
            y = x/div;
            x = x%div;
            output += c[y];
            div = div/16;
        }
        return output;
    }
    
    final int getColorInt() {
		return color;	
    }
    
  //set rgb versione int
    void setRint(int r) {
        int x = r;
        if (x>255) x=255;
        else if (x<0) x=0;
        x=x*65536; // moltiplico x (valore fra 0 e 255) per 16^4, in questo modo il numero influirà solo sulla prima e seconda cifra hex
        color = color%65536; // Rimuovo la prima e seconda cifre hex più significative
        color += x;
    }
    void setGint(int g) {
        int x = g;
        if (x>255) x=255;
        else if (x<0) x=0;
        x=x*256; // moltiplico x (valore fra 0 e 255) per 16^2, in questo modo il numero influirà solo sulla terza e quarta cifra hex
        color = color-(color%65536)+(color%256); // Rimuovo la 3^ e 4^ cifre hex più significative
        color += x;
	}
    void setBint(int b) {
        int x = b;
        if (x>255) x=255;
        else if (x<0) x=0;
        color = color-(color%256); // Rimuovo la quinta e sesta cifra più significative
        color += x;
	}
    
    //get che ritornano R G B int
    final int getRint() { // divido per 16^4 in modo da ottenere la prima e seonda cifra hex
    	return color/65536;
	} // return x| 0<x<255
    final int getGint() { // get G (terza e quarta)
    	return (color%65536)/256;
	} // return x| 0<x<255
    final int getBint() { // get B (quinta e sesta)
    	return color%256;
	} // return x| 0<x<255

    
    //set rgb versione string
    void setR(String r) {
    	this.setRint(valoreS(r,2));
	}
    void setG(String g) {
    	this.setGint(valoreS(g,2));
	}
    void setB(String b) {
    	this.setBint(valoreS(b,2));
	}
    
    //get r g b string
    String getR() {
        String output = "";
        int x = color;
        int y = x;
        int div = 1048576;
        for (int i=0; i<2; i++) {
            y = x/div;
            x = x%div;
            output += c[y];
            div = div/16;
        }
        return output;
	}
    String getG() {
        String output = "";
        int x = color%65536;
        int y = x;
        int div = 4096;
        for (int i=0; i<2; i++) {
            y = x/div;
            x = x%div;
            output += c[y];
            div = div/16;
        }
        return output;
	}
    String getB() {
        String output = "";
        int x = color%256;
        int y = x;
        int div = 16;
        for (int i=0; i<2; i++) {
            y = x/div;
            x = x%div;
            output += c[y];
            div = div/16;
        }
        return output;
	}
    
    public Status getStatus() {
        Status s = new Status();
        s.color += this.getColor();
        return s;
	}
    
    //operatori tra RGBHex

    RGBHex sum(RGBHex x) { //somma
        RGBHex aux = new RGBHex();
        int result = color + x.getColorInt();
        if (result>16777215) aux.setColorInt(16777215);
        else if (result<0) aux.setColorInt(0);
        else aux.setColorInt(result);
        return aux;
	}
    RGBHex sub(RGBHex x) { //sottrazione
        RGBHex aux = new RGBHex();
        int result = color - x.getColorInt();
        if (result<0) result = -(result); // abs(result)
        if (result>16777215) aux.setColorInt(16777215);
        else aux.setColorInt(result);
        return aux;
	}
    RGBHex mult(RGBHex x) {
        int r = this.getRint() + x.getRint();
        if (r<0) r = 0;
        if (r>255) r=255;
        int g = this.getGint() + x.getGint();
        if (g<0) g = 0;
        if (g>255) g=255;
        int b = this.getBint() + x.getBint();
        if (b<0) b = 0;
        if (b>255) b=255;
        RGBHex aux = new RGBHex(r,g,b);
        return aux;
	}
    RGBHex div(RGBHex x) {
        int r = this.getRint() - x.getRint();
        if (r<0) r = 0;
        if (r>255) r=255;
        int g = this.getGint() - x.getGint();
        if (g<0) g = 0;
        if (g>255) g=255;
        int b = this.getBint() - x.getBint();
        if (b<0) b = 0;
        if (b>255) b=255;
        RGBHex aux = new RGBHex(r,g,b);
        return aux;
	}

}
