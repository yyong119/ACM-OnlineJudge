#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 100010
#define lowbit(x) (x & (-x))
using namespace std;
int n, cnt;
long long ans;
int a[MAX_N], b[MAX_N], c[MAX_N];
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    // return res * flag;
    return res;
}
inline void add(int x) {
    for (; x <= cnt; x += lowbit(x)) ++c[x];
}
inline int query(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i)
        a[i] = read();
    memcpy(b, a, sizeof(a));
    sort(b, b + n);
    cnt = unique(b, b + n) - b;
    for (register int i = 0; i < n; ++i) {
        a[i] = lower_bound(b, b + cnt, a[i]) - b + 1;
        ans += query(cnt) - query(a[i]);
        add(a[i]);
    }
    printf("%lld", ans);
    return 0;
}
