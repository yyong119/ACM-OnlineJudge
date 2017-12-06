#include <iostream>
#include <algorithm>
int n,i;
int a[10000];
int main(){
    using namespace std;
    cin>>n;
    for (i=0; i<=n-1; i++) cin>>a[i];
    sort(a,a+n);
    for (i=0; i<=n-2; i++) cout<<a[i]<<" ";
    cout<<a[n-1];
    return 0;
}