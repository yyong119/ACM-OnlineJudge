import java.util.*;
 
public class Main {
	
	static int[][] map = new int[1002][1002];
	static int[][] sum = new int[1002][1002];
	
	static int max(int p, int q){
		if (p>q){
			return p;
		}
		return q;
	}
	
	public static void main(String[] args){
		
		Scanner input = new Scanner(System.in);
 
		int l,w,a,b;
		int maxnum = -10000;
		
		l = input.nextInt(); w = input.nextInt();
		for (int i = 1; i <= l; i++){
			for (int j = 1; j <= w; j++){
				map[i][j] = input.nextInt();
				sum[i][j] = map[i][j];
				sum[i][j] = sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			}
		}
		a = input.nextInt(); b = input.nextInt();
		for (int i = a; i <= l; i++){
			for (int j = b; j <= w; j++){
				maxnum = max(maxnum, sum[i][j]-sum[i-a][j]-sum[i][j-b]+sum[i-a][j-b]);
			}
		}
		input.close();
		System.out.println(maxnum);
	}
}