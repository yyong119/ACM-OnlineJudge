import java.util.*;
 
public class Main {
	
	public static void main(String [] args) {
		
		Scanner input = new Scanner(System.in);
		int budget, rest = 0, deposit = 0,  deadmonth = 0;
		int insufficiency = 0;
		
		for (int i = 1; i <= 12; i++) {
			rest = rest + 300;
			budget = input.nextInt();
			rest -= budget;
			if (rest >= 100) {
				deposit += rest - rest % 100;
				rest = rest % 100;
			}
			if (rest < 0) {
				insufficiency += 1;
				if (insufficiency == 1) deadmonth = i;
			}
		}
		input.close();
		if (insufficiency > 0) System.out.println("-" + deadmonth);
		else System.out.println((int) (rest + deposit * 1.2));
	}
}