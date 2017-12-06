#include <iostream>
int w[1001],v[1001],f[10001];
int n,m,i,j,k;
int main(){
    using namespace std;
    cin>>m>>n;
    for (i=1; i<=n; i++) cin>>w[i]>>v[i];
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            if ((i-w[j]>=0)&&(f[i]<f[i-w[j]]+v[j])) f[i]=f[i-w[j]]+v[j];
    cout<<f[m];
    return 0;
}