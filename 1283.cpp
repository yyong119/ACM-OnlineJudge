#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int father[1050];
int num[350]={0};
int len = 1;
void mul2(int power){
    num[0]=1;
    for (int i = 0; i < power; ++i)
    {
        int r = 0;
        int ori_len = len;
        for (int j = 0; j < ori_len ; ++j)
        {
            int tmp = num[j]*2 + r;
            r = 0;
            num[j] = ( tmp ) % 10;
            if(tmp >= 10){
                r = (tmp)/10 ;
            }
        }
        if(r!=0)
            num[len++] = r;
    }
}
 
int find(int x) {
 
    if (x != father[x]) father[x] = find(father[x]);
    return father[x];
}
 
int main() {
 
    int n, m, k = 0;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) father[i] = i;
    for (int i = 0; i < m; ++i) {
        int x,y; cin>>x>>y;
        int rootx = find(x) , rooty = find(y);
        if(rootx != rooty) father[rootx] = rooty;
    }
    for (int i = 1; i <= n; ++i) if(father[i]==i) k++;
    mul2(n-k);
    for (int i = len-1; i >=0; --i) cout<<num[i];
    return 0;
}