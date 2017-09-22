#include <iostream>
#include <algorithm>
#include <cstdio>
 
using namespace std;
typedef struct{
    int v[3];
} Tm;
bool comp(Tm a, Tm b) {
    return a.v[0] < b.v[0];
}
Tm edge[100001];
int n, m, cost, addin, tail, x, y;
int father[100001];
 
int getfather(int f) {
    if (father[f] == f) return f;
    else {
        father[f] = getfather(father[f]);
        return father[f];
    }
}
void unionxy(int x, int y) {
    father[x] = y;
}
 
int main() {
 
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &edge[i].v[1], &edge[i].v[2], &edge[i].v[0]);
    sort(edge + 1, edge + m + 1, comp);
    while (addin < n - 1) {
        tail++; x = getfather(edge[tail].v[1]); y = getfather(edge[tail].v[2]);
        if (x == y) continue;
        unionxy(x, y);
        cost += edge[tail].v[0];
        addin++;
    }
    printf("%d\n", cost);
    return 0;
}