import java.io.*;
 
public class Main {
	
	static StreamTokenizer input = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static int[][] data = new int[501][501];
	static int[][] f = new int[501][501];
	static int n, m, maxnum;
	static final int[][] movement = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	
	static int dfs(int x, int y) {
		
		int nx, ny, maxx = 0;
		
		if (f[x][y] > 0) return f[x][y];
		for (int i = 0; i < 4; i++) {
			nx = x + movement[i][0];
			ny = y + movement[i][1];
			if (nx > 0 && ny > 0 && nx <= n && ny <= m && data[nx][ny] < data[x][y])
				maxx = Math.max(maxx, dfs(nx, ny));
		}
		f[x][y] = maxx + 1;
		return f[x][y];
	}
	
	public static void main(String[] args) throws IOException {
		
		input.nextToken(); n = (int) input.nval;
		input.nextToken(); m = (int) input.nval;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				input.nextToken();
				data[i][j] = (int) input.nval;
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				f[i][j] = dfs(i, j);
				maxnum = Math.max(maxnum, f[i][j]);
			}
		System.out.println(maxnum);
	}
}