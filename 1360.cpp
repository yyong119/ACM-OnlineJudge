#include <cstdio>
#include <algorithm>
#define MAX_N 100010
using namespace std;
struct Node {
    int x, y;
    bool operator<(const Node &p) const { return y < p.y; }
} a[MAX_N];
int n, cnt, cur_r;
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    // return res * flag;
    return res;
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i) a[i].x = read(), a[i].y = read();
    sort(a, a + n);
    cur_r = a[0].y; cnt = 1;
    for (register int i = 1; i < n; ++i)
        if (a[i].x >= cur_r) {
            ++cnt;
            cur_r = a[i].y;
        }
    printf("%d", cnt);
    return 0;
}
