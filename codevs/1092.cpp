#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int a[8][2];
int i,maxt,maxd;
int main(){
    maxt=8; maxd=0;
    for (i=1; i<=7; i++){
        cin>>a[i][0]>>a[i][1];
        if (a[i][0]+a[i][1]>maxt){
                                 maxt=a[i][0]+a[i][1];
                                 maxd=i;
                                 }
    }
    cout<<maxd;
    return 0;
}