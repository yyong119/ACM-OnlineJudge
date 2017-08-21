import java.io.*;
 
public class Main {
	
	static long area, num;
	static long[] height = new long[100001];
	static StreamTokenizer input = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
 
	public static void main(String[] args) throws IOException {
		
		input.nextToken();
	    num = (long) input.nval;
	    for (int i = 0; i < num; i++) {
	    	input.nextToken();
	        height[i] = (long) input.nval;
	    }
 
	    for(int i = 0; i < num; i++){
	        int width=1;
	        for(int x = i - 1; x >= 0; x--){
	            if (height[x] < height[i]) break;
	            width++;
	        }
	        for(int y = i + 1; y < num; y++){
	            if (height[y] < height[i]) break;
	            width++;
	        }
	        area = Math.max(area, width * height[i]);
	    }
	    System.out.println(area);	
	}
}