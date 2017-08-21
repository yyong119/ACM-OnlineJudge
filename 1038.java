import java.util.*;
import java.io.*;
 
public class Main {
	
	static StreamTokenizer input = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static long m, k, now;
	static ArrayList<Integer> que = new ArrayList<Integer>();
	
	public static void main(String[] args) throws IOException{
		
		input.nextToken();
		m = (int) input.nval;
		for (int i = 1; i <= m; i++){
			que.add(i);
		}
		for (int i = 1; i < m; i++){
			input.nextToken();
			k = (int) input.nval;
			now -= 1;
			now = (now + k % que.size()) % que.size();
			if (now == -1) now = que.size() - 1;
			que.remove((int) now);
		}
		System.out.print(que.get(0));
	}
}