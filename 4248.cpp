#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_N 100010
#define min(x, y) ((x) < (y) ? (x) : (y))
using namespace std;
struct Node {
    int x, val;
} a[MAX_N], b[MAX_N];
int n, xa, xb, ans = 0x7fffffff;
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
inline bool cmp_asc(const Node &p, const Node &q) {
    return p.val == q.val ? p.x < q.x : p.val < q.val;
}
inline bool cmp_dec(const Node &p, const Node &q) {
    return p.val == q.val ? p.x < q.x : p.val > q.val;
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i) {
        a[i].val = read(); a[i].x = i;
    }
    for (register int i = 0; i < n; ++i) {
        b[i].val = read(); b[i].x = i;
    }
    sort(a, a + n, cmp_dec);
    sort(b, b + n, cmp_asc);

    // 0 ~ xa have the same maximum value with index ascending
    while (xa < n - 1 && a[xa].val == a[xa + 1].val) ++xa;
    // 0 ~ xb have the same minimum value with index ascending
    while (xb < n - 1 && b[xb].val == b[xb + 1].val) ++xb;

    for (register int i = 0, j = 0; i <= xa && j <= xb; ) {
        // printf("###%d %d %d %d\n", i, j, a[i].x, b[j].x);
        ans = min(ans, abs(a[i].x - b[j].x));
        // printf("%d\n", ans + 1);
        if (a[i].x < b[j].x) ++i;
        else ++j;
    }
    printf("%d", ans + 1);
    return 0;
}
