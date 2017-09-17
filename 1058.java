import java.io.*;
 
public class Main {
 
	static StreamTokenizer input = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static long m, n;
	
	public static void main(String[] args) throws IOException {
		
		input.nextToken();
		m = (long) input.nval;
		input.nextToken();
		n = (long) input.nval;
		System.out.println(m + n);
	}
}