#include <iostream>
#include <cstring>
int n,i,num;
char a[100];
bool p;
int main(){
    using namespace std;
    cin>>n;
    for (int k=1; k<=n; k++){
        cin>>a; p=true; num=0;
        for (i=0; i<=strlen(a)-1; i++){
            if (a[i]=='(') num++;else num--;
            if (num<0){p=false; break;}
        }
        if ((p)&&(num==0)) cout<<"YES"<<endl;else cout<<"NO"<<endl;
    }
    return 0;
}