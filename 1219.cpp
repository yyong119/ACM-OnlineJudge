#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 200020
using namespace std;
int a[MAX_N << 1], b[MAX_N << 1], tree[MAX_N << 1];
int n, cnt;
long long ans;
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
inline void update(int x) {
    for (; x <= cnt; x += x & -x)
        ++tree[x];
}
inline int query(int x) {
    int res = 0;
    for (; x; x -= x & -x)
        res += tree[x];
    return res;
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i) {
        a[i] = read();
        a[i + n] = a[i] << 1;
    }
    memcpy(b, a, sizeof(a));
    sort(b, b + (n << 1));
    cnt = unique(b, b + (n << 1)) - b;
    for (register int i = 0; i < (n << 1); ++i)
        a[i] = lower_bound(b, b + cnt, a[i]) - b + 1;

    update(a[0]);
    for (register int i = 1; i < n; ++i) {
        ans += (long long)query(cnt) - (long long)query(a[i + n]);
        update(a[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
