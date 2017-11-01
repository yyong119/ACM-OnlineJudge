#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long a,b,total,i,temp;
long x[10000];
bool q=true;
int main(){
    cin>>a>>b;
    total=0;
    while ((b!=0)&&(a!=0)){
          if (a>b){temp=a; a=b; b=temp;}
          if (total>10000){cout<<-1; return 0;}
          x[total]=a;
          for (i=0; i<=total-1; i++) if (a==x[i]){cout<<-1; q=false; break;}
          if (q==false) break;
          b-=a; a+=a;
          total++;
    }
    if (q==true) cout<<total;
    return 0;
}