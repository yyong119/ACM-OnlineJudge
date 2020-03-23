#include <iostream>
#include <cstdio>
#define MAX_N 1000010
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;
int n, len, ans;
int a[MAX_N], l[MAX_N], r[MAX_N], que[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    // if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    // return res * flag;
    return res;
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i) a[i] = read();
    // calc left
    len = 1; que[0] = a[0];
    for (register int i = 1; i < n; ++i) {
        int tmp = lower_bound(que, que + len, a[i]) - que;
        l[i] = tmp;
        if (tmp == len) que[len++] = a[i];
        else que[tmp] = a[i];
    }
    // calc right
    len = 1; que[0] = a[n - 1];
    for (register int i = n - 2; i >= 0; --i) {
        int tmp = lower_bound(que, que + len, a[i]) - que;
        r[i] = tmp;
        if (tmp == len) que[len++] = a[i];
        else que[tmp] = a[i];
    }
    // calc maximum
    ans = 0;
    for (register int i = 0; i < n; ++i)
        ans = max(ans, l[i] + r[i] + 1);
    printf("%d", n - ans);
    return 0;
}
