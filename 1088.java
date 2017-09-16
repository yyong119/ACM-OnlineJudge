import java.util.*;
 
public class Main {
	
	static int n, i, j, cost;
	static boolean[] flag = new boolean[20];
	static int[][] map = new int[20][20];
	static Scanner input = new Scanner(System.in);
	
	public static void dfs(int depth, int temp, int pos){
		
		if (temp >= cost) return;
		if (depth == n) cost = Math.min(cost, temp + map[pos][1]);
		else
			for (int i = 2; i <= n; i++)
				if ((!flag[i])&&(i != pos)){
					flag[i] = true;
					dfs(depth+1, temp +map[pos][i], i);
					flag[i] = false;
				}
 
	}
	public static void main(String[] args){
		
		n = input.nextInt();
		cost = 2000 * 15;
		for (int i = 1; i <= 15; i++) flag[i] = false;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) map[i][j] = input.nextInt();
		dfs(1,0,1);
		input.close();
		System.out.println(cost);
	}
	
}