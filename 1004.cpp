#include <iostream>
long m,u,f,d,t,i,n;
char si[100001];
int main(){
    using namespace std;
    cin>>m>>t>>u>>f>>d;
    for (i=1; i<=t; i++) cin>>si[i];
    while(m>=0){
        n++;
        if ((si[n]=='u')||(si[n]=='d')) m=m-u-d;
        else if(si[n]=='f') m=m-f-f;
    }
    cout<<n-1;
    return 0;
}