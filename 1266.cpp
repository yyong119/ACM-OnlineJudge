#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 50010
#define MAX_M 100010
 
struct node{
    int x, y, c;
} edge[MAX_M];
int n, m;
int par[MAX_N];
 
inline bool cmp(node p, node q) {
    return p.c < q.c;
}
 
int find_par(int x) {
    if (par[x] == x) return x;
    par[x] = find_par(par[x]);
    return par[x];
}
 
int main() {
 
    scanf("%d%d", &n, &m);
    if (n <= 2) {
        printf("0");
        return 0;
    }
    for (int i = 0; i < m; ++i)
        scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].c);
    sort(edge, edge + m, cmp);
    int delta_min = 0x7fffffff;
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= n; ++j)
            par[j] = j;
        int cnt = 1;
        for (int j = i; j < m && edge[j].c - edge[i].c < delta_min; ++j) {
            int x = find_par(edge[j].x), y = find_par(edge[j].y);
            if (x != y) {
                par[x] = y;
                ++cnt;
                if (cnt == n) {
                    delta_min = edge[j].c - edge[i].c;
                    break;
                }
            }
        }
    }
    printf("%d\n", delta_min);
    return 0;
}