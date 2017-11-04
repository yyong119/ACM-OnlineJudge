#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
long a[200001];
long n,m,i,j,k,total;
int main(){
    scanf("%ld",&n);
    for (i=1; i<=n; i++){
        scanf("%ld",&a[i]);
    }
    sort(a,a+n+1); printf("%ld",a[1]); total=1;
    for (i=2; i<=n; i++){
        if (a[i]==a[i-1]){
           total++;
        }else
        {
             printf("%s%ld\n"," ",total);
             printf("%ld",a[i]);
             total=1;
        }
    }
    printf("%s%ld"," ",total);
    return 0;
}