#include <cstdio>
#define MAX_N 10010
using namespace std;
int n, m, l, r, x, cnt;
int a[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    // return res * flag;
    return res;
}
int main() {
    n = read(); m = read();
    for (register int i = 1; i <= n; ++i) a[i] = read();
    for (register int i = 0; i < m; ++i) {
        l = read(), r = read(), x = read();
        if (x < l || x > r) {
                printf("Yes\n");
                continue;
        }
        cnt = 0;
        for (register int j = l; j <= r; ++j)
            if (a[j] < a[x]) ++cnt;
        if (cnt == x - l) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}