#include <cstdio>
#include <algorithm>
#define MAX_N 5010
using namespace std;
struct Node {
    int l, r;
    bool operator<(const Node &p) const {
        return l == p.l ? r < p.r : l < p.l;
    }
} a[MAX_N];
int n, max_f, max_e;
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
    for (register int i = 0; i < n; ++i)
        a[i].l = read(), a[i].r = read();
    sort(a, a + n);
    int cur_l = a[0].l, cur_r = a[0].r;
    for (register int i = 1; i < n; ++i)
        if (a[i].l > cur_r) {
            max_e = max(max_e, a[i].l - cur_r);
            max_f = max(max_f, cur_r - cur_l);
            cur_l = a[i].l;
            cur_r = a[i].r;
        }
        else cur_r = max(cur_r, a[i].r);
    max_f = max(max_f, cur_r - cur_l);
    printf("%d %d", max_f, max_e);
    return 0;
}
