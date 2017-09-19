#include <algorithm>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
const int up = 1000001;
int a1[up], a2[up], f1[up], f2[up], g[up];
 
int main()
{
    int n, k, maxn = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a1[i]);
        a2[n - i + 1] = a1[i];
    }
    memset(g, 0x7f, sizeof(g));
    for(int i = 1; i <= n; i++)
    {
        k = lower_bound(g + 1, g + n + 1, a1[i]) - g;
        f1[i] = k;
        g[k] = a1[i];
    }
    memset(g, 0x7f, sizeof(g));
    for(int i = 1; i <= n; i++)
    {
        k = lower_bound(g + 1, g + n + 1, a2[i]) - g;
        f2[n - i + 1] = k;
        g[k] = a2[i];
    }
    for(int i = 1; i <= n; i++) maxn = max(maxn, f1[i] + f2[i]);
    printf("%d\n", n + 1 - maxn);
}