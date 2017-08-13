import java.math.BigInteger;
import java.util.*;
 
public class Main {
     
    private static Scanner in;
    public static void main(String[] args) {
        in = new Scanner(System.in);
        long n=in.nextLong();
        Main m =new Main();
        if(n%2040==0){
            System.out.print(0);
        }else{
            BigInteger res = m.fib(n%2040);
            System.out.print((res.divideAndRemainder(new BigInteger("2010")))[1]);
        }
    }
    BigInteger fib(long n){
         if(n==1 || n==2){
             return new BigInteger("1");
         }else{
             BigInteger pnum=new BigInteger("1");
             BigInteger cnum=new BigInteger("1");
             for(int i=3;i<=n;i++){
                 cnum= cnum.add(pnum);
                 pnum =cnum.subtract(pnum);
             }
             return cnum;
         }
    }
}