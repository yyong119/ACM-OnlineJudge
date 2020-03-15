#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX_N 1010
using namespace std;
int n, w;
int a[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
int main() {
    n = read(), w = read();
    for (register int i = 0; i < n; ++i) a[i] = read();
    sort(a, a + n);
    int k = lower_bound(a, a + n, w) - a;
    if (!k)
        printf("%d", a[0]);
    else
        // if (a[k] - w <= w - a[k - 1])
        if (a[k] + a[k - 1] <= (w << 1))
            printf("%d", a[k]);
        else
            printf("%d", a[k - 1]);
    return 0;
}
