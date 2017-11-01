#include <iostream>  
#include <algorithm>  
using namespace std;  
const int MAXN = 105;  
const int INF = 2147483647;  
int i, j, n;  
long long ans = 0;  
int edge[MAXN][MAXN], key[MAXN], p[MAXN], vis[MAXN] = {0},
    f[MAXN], l[MAXN], m = 0; 
int main()  
{  
    cin >> n;  
    for(i = 1; i <= n; i++)for(j = 1; j <= n; j++) cin >> edge[i][j];  
    for(i = 1; i <= n; i++) key[i] = INF;  
    key[1] = 0;
    p[1] = 1;  
    int Mini, Min;  
    for(i = 0; i < n; i++) 
    {  
        Min = INF;  
        for(j = 1; j <= n; j++) if(!vis[j] && key[j] < Min){Mini = j; Min = key[j];}
        vis[Mini] = 1;
        ans += key[Mini];   
        if(key[Mini])  
        {  
            f[m] =   min(p[Mini], Mini); 
            l[m++] = max(p[Mini], Mini); 
        }  
        for(j = 1; j <= n; j++) 
            if(!vis[j] && edge[Mini][j] < key[j])  
            {key[j] = edge[Mini][j]; p[j] = Mini;}  
    }  
    cout << m << endl;  
    for(i = 0; i < m; i++) cout << f[i] << ' ' << l[i] << endl;  
    cout << ans;  
    return 0;  
}  