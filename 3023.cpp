#include <cstdio>
#include <cstring>
#define MAX_N 105
#define MAX_T 265
#define lowbit(x) ((x) & (-x))
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;
int n;
int a[MAX_N], l[MAX_N], r[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i) a[i] = read();
    for (register int i = 1; i < n; ++i)
        for (register int j = 0; j < i; ++j)
            if (a[i] > a[j])
                l[i] = max(l[i], l[j] + 1);
    for (register int i = n - 2; i >= 0; --i)
        for (register int j = i + 1; j < n; ++j)
            if (a[i] > a[j])
                r[i] = max(r[i], r[j] + 1);
    int ans = 0;
    for (register int i = 0; i < n; ++i)
        ans = max(ans, l[i] + r[i] + 1);
    printf("%d", n - ans);
    return 0;
}
