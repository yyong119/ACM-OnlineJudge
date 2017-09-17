import java.util.*;
import java.math.*;
 
public class Main {
	
	static BigInteger a;
	static BigInteger b;
	static Scanner input = new Scanner(System.in);
	static String aa = new String();
	static String bb = new String();
	
	public static void main(String[] args) {
		
		aa = input.next(); bb = input.next();
		a = new BigInteger(aa); b = new BigInteger(bb);
		System.out.println(a.divide(b));
	}
}