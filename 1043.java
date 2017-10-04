import java.util.*;
import java.io.*;
public class Main {
	
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	
	static Scanner input = new Scanner(System.in);
	static Queue<Integer> queue = new LinkedList<Integer>();
	static boolean flag = false, complete = true;
	static int n, node, now;
	static int[][] tree = new int[1000001][3];
 
	public static void main(String[] args) throws IOException {
		
		in.nextToken();
		n = (int) in.nval;
//		n = input.nextInt();
		for (int i = 1; i < n; i++) {
			in.nextToken();
			node = (int) in.nval;
//			node = input.nextInt();
			tree[i][0] = node;
			if (tree[node][1] == 0) tree[node][1] = i;
			else tree[node][2] = i;
		}
		if (tree[0][1] != 0) queue.offer(tree[0][1]);
		if (tree[0][2] != 0) queue.offer(tree[0][2]);
 
		while (!queue.isEmpty()) {
			now = queue.poll();
			if ((tree[now][1] == 0)&&(tree[now][2] == 0)) flag = true;
			if (tree[now][1] != 0) {
				queue.offer(tree[now][1]);
				if (flag ==true) {
					complete = false;
					break;
				}
			}
			if (tree[now][2] != 0) queue.offer(tree[now][2]);
		}
		System.out.println(complete);
	}
}