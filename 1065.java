import java.io.*;
public class Main {
	static int[][] martix = new int[1001][1001];
	static String str1, str2;
	static StreamTokenizer input = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static int maxlen;
	static void LCS(String str1, String str2) {
        for (int i = 0; i <= str1.length(); i++)
            martix[i][0] = 0;
 
        for (int j = 0; j <= str2.length(); j++)
            martix[0][j] = 0;
 
        for (int i = 1; i <= str1.length(); i++)
            for (int j = 1; j <= str2.length(); j++)
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) 
                	martix[i][j] = martix[i - 1][j - 1] + 1;
                else 
                	martix[i][j] = Math.max(martix[i][j - 1], martix[i - 1][j]);
    }
	public static void main(String[] args) throws IOException {
		input.nextToken();
		str1 = input.sval;
		input.nextToken();
		str2 = input.sval;
		LCS(str1, str2);
		for (int i = 0; i <= str1.length(); i++)
			for (int j = 0; j <= str2.length(); j++)
				maxlen = Math.max(maxlen, martix[i][j]);
		System.out.println(maxlen);
	}
}