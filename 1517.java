import java.util.*;
import java.math.BigInteger;
 
public class Main {
 
	void solve() {
		
		Scanner input = new Scanner(System.in);
		BigInteger a;
		BigInteger b;
		String aa, bb;
		aa = input.next(); bb = input.next();
		input.close();
		a = new BigInteger(aa); b = new BigInteger(bb);
		System.out.println(a.add(b.negate()));
	}
	public static void main(String[] args) {
		
		Main OJ = new Main();
		OJ.solve();
	}
}