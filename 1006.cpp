#include <iostream>
#include <cmath>
int num[1000001],pre[1000001];
int n,i,nmax,j,flag;
int main(){
    using namespace std;
    cin>>n;
    if (n<=100){
        for (i=1; i<=n; i++){
            cin>>num[i];
            num[i]+=num[i-1];
        }
        for (i=1; i<n; i++)
            for (j=i+1; j<=n; j++) nmax=max(num[j]-num[i-1],nmax);
    }else{
        for (i=1; i<=n; i++) cin>>num[i];
        for (i=1; i<=n; i++){
            if (pre[i-1]+num[i]<0) flag=0;
            else{
                pre[i]=pre[i-1]+num[i];
                flag++;
            }
            if ((pre[i]>nmax)&&(flag>=2)) nmax=pre[i];
        }
    }
    if (nmax) cout<<nmax;else cout<<"Game Over";
    return 0;
}