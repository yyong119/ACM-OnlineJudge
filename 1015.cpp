#include <iostream>
#include <cstring>
int a[1000],b[1000],c[2001];
char p[1000],q[1000];
int i,j,k,length,lp,lq;
int main(){
    using namespace std;
    cin>>p>>q; lp=strlen(p); lq=strlen(q);
    for (i=0; i<=lp-1; i++) a[lp-i]=int(p[i]-'0');
    for (i=0; i<=lq-1; i++) b[lq-i]=int(q[i]-'0');
    for (i=1; i<=lp; i++)
        for (j=1; j<=lq; j++){
                c[i+j-1]+=a[i]*b[j];
                c[i+j]+=c[i+j-1]/10;
                c[i+j-1]=c[i+j-1]%10;
        }
    for (i=1; i<=lp+lq+1; i++){
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
    }
    for (i=2000; i>=1; i--)
    if (c[i]){
        length=i; break;
    }
    for (i=length; i>=1; i--) cout<<c[i];
    return 0;
}