import java.util.*;
 
public class Main {
	static int[][] num = new int[1005][2502];
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int a, b, c, n;
		a = input.nextInt(); b = input.nextInt();
		c = input.nextInt(); n = input.nextInt();
		input.close();
		num[4][0] = 1; num[4][1] = 1;
		for (int i = 5; i <= n+4; i++) {
	        for (int j = 1; j <= num[i-1][0]; j++) num[i][j] += num[i-1][j];
	        for (int j = 1; j <= num[i-3][0]; j++) num[i][j] += c*num[i-3][j];
	        for (int j = 1; j <= num[i-2][0]; j++) num[i][j] += b*(num[i-2][j]-num[i-3][j]);
	        for (int j = 1; j <= num[i-1][0]; j++) num[i][j] += a*(num[i-1][j]-num[i-2][j]);
	        for (int j = 1; j <= 2500; j++){
	            num[i][j+1] += num[i][j] / 10;
	            num[i][j] = num[i][j] % 10;
	        }
	        for (int j = 2500; j >= 1; j--)
	        	if (num[i][j] != 0) {
	        		num[i][0] = j;
	        		break;
	        	}
		}
		for (int i = num[n+4][0]; i >= 1; i--)
			System.out.print(num[n+4][i]);
	}
}