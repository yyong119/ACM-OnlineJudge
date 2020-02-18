#include <cstdio>
#include <algorithm>
#include <iostream>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define MAX_N 505
using namespace std;
int n, sum, maxheight;
int a[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
inline void dfs(int idx, int l, int r, int left) {
    if (abs(l - r) > left || l + r + left <= (maxheight << 1))
        return;
    if (l == r)
        maxheight = max(maxheight, l);
    if (++idx == n) return;
    left -= a[idx];
    dfs(idx, l + a[idx], r, left);
    dfs(idx, l, r + a[idx], left);
    dfs(idx, l, r, left);
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i) {
        a[i] = read(); sum += a[i];
    }
    sort(a, a + n, greater<int>());
    dfs(0, a[0], 0, sum - a[0]);
    dfs(0, 0, 0, sum - a[0]);
    if (maxheight) printf("%d", maxheight);
    else printf("Impossible");
    return 0;
}
