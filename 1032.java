import java.util.*;
 
public class Main {
	
	static Scanner input = new Scanner(System.in);
	static int[][] a = new int[4][20001];
	static int m, n;
	
	public static void main(String[] args) {
		
		m = input.nextInt(); n = input.nextInt();
		for (int i = 0; i < 20000; i++) a[0][i] = i + 1;
		for (int i = 1; i < 4; i++){
			a[i][0] = a[i - 1][1];
			for (int j = 1; j < 20000; j++)
				a[i][j] = a[i - 1][a[i][j - 1]];
		}
		System.out.println(a[m][n]);
	}
}