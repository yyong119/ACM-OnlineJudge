import java.io.*;
 
public class Main {
 
	StreamTokenizer input = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	int[][] num = new int[50][3];
	int n;
	
	public void solveit() throws IOException{
		
		input.nextToken(); n = (int) input.nval;
		num[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			
			num[i][1] = num[i - 1][0];
			num[i][2] = num[i - 1][1] + num[i - 1][2];
			num[i][0] = num[i][2];
		}
		System.out.println(num[n][0] + num[n][1] + num[n][2]);
	}
	
	public static void main(String[] args) throws IOException {
		
		try {
			Main OJ = new Main();
			OJ.solveit();
		} catch(IOException ex) {
			ex.printStackTrace();
		}
	}
}