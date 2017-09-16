import java.util.*;
 
public class Main {
 
     
    private static Scanner in;
 
    public static void main(String[] args) {
        in = new Scanner(System.in);
        int n =in.nextInt();
        int d[] =new int[n];
        Interval it[] = new Interval[n];
        for(int i=0;i<n;i++){
            it[i] =new Interval();
            it[i].x=in.nextInt();
            it[i].y=in.nextInt();
            d[i] = it[i].y;
        }
        int count=0;
        int s=0;
        Arrays.sort(it);
        int a = d[0];
        for(int i=0;i<n;i++){
            if(a<d[i]){
                a=d[i];
            }
        }
        for(int i=it[0].x;i<a;i++){
            for(int j=s;j<n;){
                if(i>=it[j].x&&i<it[j].y){
                    count = count+it[j].y-i;
                    i=it[j].y-1;
                    break;
                }else if(i>=it[j].y){
                    s++;
                    i--;
                    break;
                }else{
                    i=it[j].x;
                    count++;
                    break;
                }
            }
        }
        System.out.println(count);
    }
        static class Interval implements Comparable<Interval>{
            int x;
            int y;
            @Override
            public int compareTo(Interval arg0) {
                if(this.x<arg0.x){
                    return -1;
                }else if(this.x==arg0.x){
                    return 0;
                }else{
                    return 1;
                }
                 
            }
        }
}