#include <iostream>
#include <cstring>
#include <iomanip>
int n,num,x,y,i,j;
int m[151][151];
int main(){
    using namespace std;
    memset(m,0,sizeof(m));
    cin>>n; m[1][n+1]=1; m[n+1][n]=1; m[n][0]=1;
    x=1; y=1; m[x][y]=1; num=1;
    while (num<n*n){
        while (m[x][y+1]==0){
            y++; num++; m[x][y]=num;
        }
        while (m[x+1][y]==0){
            x++; num++; m[x][y]=num;
        }
        while (m[x][y-1]==0){
            y--; num++; m[x][y]=num;
        }
        while (m[x-1][y]==0){
            x--; num++; m[x][y]=num;
        }
    }
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++) cout<<setw(6)<<m[i][j];
        cout<<endl;
    }
    return 0;
}