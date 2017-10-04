#include <iostream>
int num[1005][2501];
int a,b,c,n,i,j;
int main(){
    using namespace std;
    cin>>a>>b>>c>>n;
    num[4][0]=1; num[4][1]=1;
    for (i=5; i<=n+4; i++){
        for (j=1; j<=num[i-1][0]; j++) num[i][j]+=num[i-1][j];
        for (j=1; j<=num[i-3][0]; j++) num[i][j]+=c*num[i-3][j];
        for (j=1; j<=num[i-2][0]; j++) num[i][j]+=b*(num[i-2][j]-num[i-3][j]);
        for (j=1; j<=num[i-1][0]; j++) num[i][j]+=a*(num[i-1][j]-num[i-2][j]);
        for (j=1; j<=2500; j++){
            num[i][j+1]+=num[i][j]/10;
            num[i][j]=num[i][j]%10;
        }
        for (j=2500; j>=1; j--) if (num[i][j]){num[i][0]=j; break;}
    }
    for (i=num[n+4][0]; i>=1; i--) cout<<num[n+4][i];
    return 0;
}