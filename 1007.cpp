#include <iostream>
#include <cstring>
#include <cstdlib>
char a[202],b[202];
int i,j,k,l,dot1,dot2,maxint,maxfra;
int int1[201],int2[201],fra1[2],fra2[2];
int ansint[201],ansfra[2];
int main(){
    using namespace std;
    cin>>a>>b;
    for (i=0; i<=strlen(a)-1; i++)
        if (a[i]=='.') {dot1=i; break;}
    for (i=0; i<=strlen(b)-1; i++)
        if (b[i]=='.') {dot2=i; break;}
    for (i=dot1-1; i>=0; i--) int1[dot1-i-1]=int(a[i]-'0');
    for (i=dot1+1; i<=strlen(a)-1; i++) fra1[i-dot1-1]=int(a[i]-'0');
    for (i=dot2-1; i>=0; i--) int2[dot2-i-1]=int(b[i]-'0');
    for (i=dot2+1; i<=strlen(b)-1; i++) fra2[i-dot2-1]=int(b[i]-'0');
    for (i=0; i<=200; i++){
        ansint[i]+=int1[i]+int2[i];
        if (ansint[i]>=10){ ansint[i+1]+=1; ansint[i]-=10;}
    }
    ansfra[0]=fra1[0]+fra2[0]; ansfra[1]=fra1[1]+fra2[1];
    if (ansfra[1]>=10){ ansfra[0]++; ansfra[1]-=10;}
    if (ansfra[0]>=10){ ansfra[0]-=10; ansint[0]++;}
    for (i=0; i<=200; i++)
        if (ansint[i]>=10) {ansint[i]-=10; ansint[i+1]++;}
    for (i=200; i>=0; i--) if (ansint[i]) { maxint=i; break;}
    for (i=200; i>=0; i--) if (ansfra[i]) { maxfra=i; break;}
    for (i=maxint; i>=0; i--) cout<<ansint[i];
    cout<<"."; cout<<ansfra[0]<<ansfra[1];
    return 0;
}