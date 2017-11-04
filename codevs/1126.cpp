#include <cstdio>
long a,b,n,ans=0;
int main(){
    scanf("%ld%ld",&a,&b);
    for (int i=a; i<=b; i++){
        n=i;
        while (n!=0){ 
              if (n%10==2) ans++;
              n=n/10;
        }
    }
    printf("%ld",ans);
    return 0;
}