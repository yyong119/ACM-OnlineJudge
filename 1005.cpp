#include <iostream>
int n,i,j,k,l;
int a[10][10],c[10];
bool te;
int main(){
    using namespace std;
    cin>>n;
    while(n){
        te=false;
        for (i=1; i<=9; i++){
            for (j=1; j<=9; j++) c[j]=0;
            for (j=1; j<=9; j++){
                    cin>>a[i][j];
                    c[a[i][j]]++;
            }
            for (j=1; j<=9; j++) if (c[j]>1) te=true;
        }
        for (i=1; i<=3; i++)
        for (j=1; j<=3; j++){
            for (k=1; k<=9; k++) c[k]=0;
            for (k=3*i-2; k<=3*i; k++)
            for (l=3*j-2; l<=3*j; l++)
                c[a[k][l]]++;
            for (k=1; k<=9; k++) if (c[k]>1) te=true;
        }
        if (te) cout<<"Wrong\n";else cout<<"Right\n";
        n--;
    }
    return 0;
}