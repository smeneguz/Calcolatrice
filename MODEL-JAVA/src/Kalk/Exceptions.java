package Kalk;

public class Exceptions extends Throwable {
	private String err;
	public Exceptions (String s) {
		err = s;
	    //System.out.println(err);
	}
	public String getErr() { return err;}
}

