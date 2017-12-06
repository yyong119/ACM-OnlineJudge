#include <iostream>
#include <cstring>
int s[601][601],c[601][601];
int n,i,j,k,m;
int main(){
    using namespace std;
    cin>>n;
    while (n){
        cin>>m>>k; memset(s,0,sizeof(s)); memset(c,0,sizeof(c));
        for (i=1; i<=m; i++) for (j=1; j<=m; j++) cin>>s[i][j];
        if (k==0){
            for (i=1; i<=m; i++)
                for (j=1; j<=m; j++) c[i][j]=s[i][m-j+1];
        }else
        if (k==1){
            for (i=1; i<=m; i++)
                for (j=1; j<=m; j++) c[i][j]=s[m-i+1][j];
        }else
        if (k==2){
            for (i=1; i<=m; i++)
                for (j=1; j<=m; j++) c[i][j]=s[j][i];
        }
        for (i=1; i<=m; i++){
            for (j=1; j<=m-1; j++) cout<<c[i][j]<<" ";
            cout<<c[i][m]<<endl;
        }
        n--;
    }
    return 0;
}