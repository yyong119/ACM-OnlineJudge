#include<cstdio>  
  
int gcd(int a,int b){return (b)?gcd(b,a%b):a;}  
inline int lcm(int a,int b){ return a/gcd(a,b)*b; }  
  
int main()  
{  
    int x,y;  
    scanf("%d%d",&x,&y);  
    int res=0;  
    int a,b;  
    for(a=x;a<=y;a++)  
        if(y%a==0)  
        {  
            b=y/a*x;  
            if(gcd(a,b)==x&&lcm(a,b)==y) res++;  
        }  
    printf("%d\n",res);  
    return 0;  
}  