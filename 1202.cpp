#include <iostream>
#include <cstring>
int a[1000001],b[1000001],c[1000001];
char p[1000000],q[1000000];
int i,length;
int main(){
    using namespace std;
    cin>>p>>q;
    for (i=0; i<=strlen(p)-1; i++) a[strlen(p)-i]=int(p[i]-'0');
    for (i=0; i<=strlen(q)-1; i++) b[strlen(q)-i]=int(q[i]-'0');
    if (strlen(p)>=strlen(q)) length=strlen(p);
        else length=strlen(q);
    for (i=1; i<=length; i++){
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10; c[i]=c[i]%10;
    }
    if (c[length+1]) length++;
    for (i=length; i>=1; i--) cout<<c[i];
    return 0;
}
