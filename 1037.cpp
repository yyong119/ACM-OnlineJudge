#include <iostream>
#include <algorithm>
 
int hq[10001], lq[10001];
int n, m, countl;
using namespace std;
 
int main(){
    cin>>n>>m;
    for (int i = 0; i < n; i++) cin>>hq[i];
    for (int i = 0; i < m; i++) cin>>lq[i];
    sort(hq, hq + n);
    sort(lq, lq + m);
    for (int i = 0; i < n; i++)
        if ((hq[i] > lq[countl])&&(countl < m)) countl++;
    cout<<n + countl<<endl;
}