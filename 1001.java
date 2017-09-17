import java.util.*;
 
public class Main {
 
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int pheight = input.nextInt();
		int cheight = input.nextInt();
		int num = input.nextInt();
		int temp;
		int count = 0;
		
		for (int i = 0; i < num; i++) {
			temp = input.nextInt();
			if (pheight + cheight >= temp) {
				count++;
			}
		}
		input.close();
		System.out.println(count);
	}
}