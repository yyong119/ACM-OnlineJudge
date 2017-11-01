#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int a[11];
int p,q;
int main(){
    for (int i=1; i<=10; i++) cin>>a[i];
    cin>>p;
    for (int i=1; i<=10; i++) 
        if (a[i]<=p+30) q++;
    cout<<q<<endl;
    return 0;
}