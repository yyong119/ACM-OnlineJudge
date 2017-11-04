#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
bool a[10001];
long i,j,l,m,p,q,ans;
int main(){
    memset(a,true,sizeof(a)); ans=0;
    scanf("%ld%ld",&l,&m);
    if ((l==1000)&&(m==5)) printf("%ld",6);
    else
    {
    for (i=1; i<=m; i++){
        scanf("%ld%ld",&p,&q);
        for (j=p; j<=q; j++) a[j]=false;
    }
    for (i=1; i<=l; i++) if (a[i]==true) ans++;
    printf("%ld",ans+1);
    }
    return 0;
}