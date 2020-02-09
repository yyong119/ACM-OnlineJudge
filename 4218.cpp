#include <cstdio>
#define MAX_N 2000020
using namespace std;
struct Node {
    int x, val;
};
int n, k, ans;
int a[MAX_N];
Node sw[MAX_N]; int l, r; // dequeue
bool b[MAX_N];
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}

int main() {
    n = read(); k = read();
    for (register int i = 1; i <= n; ++i) a[i] = read();
    // check left side of each number
    l = 0, r = -1;
    for (register int i = 1; i <= n; ++i) {
        while (l <= r && sw[r].val <= a[i]) --r;
        sw[++r].x = i; sw[r].val = a[i];
        if (sw[l].val > (a[i] << 1)) b[i] = true;
        if (i > k && sw[l].x <= i - k) ++l;
    }
    // check right side of each number
    l = 0, r = -1;
    for (register int i = n; i > 0; --i) {
        while (l <= r && sw[r].val <= a[i]) --r;
        sw[++r].x = i; sw[r].val = a[i];
        if (!b[i] && sw[l].val > (a[i] << 1)) b[i] = true;
        if (i <= n - k && sw[l].x >= i + k) ++l;
    }
    for (register int i = 1; i <= n; ++i) ans += b[i];
    printf("%d\n", ans);
    return 0;
}
