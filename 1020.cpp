#include <iostream>
#include <cstring>
#include <cmath>
bool b[50000];
int num[50000];
long n,i,j,temp;
int main(){
    using namespace std;
    memset(b,true,sizeof(b)); memset(num,0,sizeof(num));
    cin>>n; b[1]=false; temp=n; cout<<n<<"=";
    for (i=2; i<=50000; i++)
        if (b[i]) for (j=2; j<=50000/i; j++) b[i*j]=false;
    for (i=2; i<=sqrt(n); i++){
        if ((b[i])&&(temp%i==0))
        while (temp%i==0){
            temp=temp/i; num[i]++;
        }
    }
    for (i=2; i<=sqrt(n); i++)
        if (num[i]) cout<<i<<"("<<num[i]<<")";
    if (temp>1) cout<<temp<<"(1)";
    return 0;
}