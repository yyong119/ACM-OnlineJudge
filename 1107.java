import java.io.*;
 
public class Main {
 
	static StreamTokenizer input = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static long m, n;
	
	public static void main(String[] args) throws IOException {
		
		input.nextToken();
		m = (long) input.nval;
		for (int i = 0; i < m; ++i) {
			input.nextToken();
			n = (long) input.nval;
			System.out.println(n == 0 ? "no" : "yes");
			System.out.println('\n');
		}
	}
}