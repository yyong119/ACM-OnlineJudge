#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX_N 510
using namespace std;
struct Node {
    int x, t;
    bool operator<(const Node &p) const {
        return x > p.x;
    }
} a[MAX_N];
int n, ans;
priority_queue<Node> q;
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
inline bool cmp(const Node &p, const Node &q) {
    return p.t == q.t ? p.x > q.x : p.t < q.t;
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i) a[i].t = read();
    for (register int i = 0; i < n; ++i) a[i].x = read();
    sort(a, a + n, cmp);
    q.push(a[0]);
    for (register int i = 1; i < n; ++i)
        if (a[i].t > q.size())
            q.push(a[i]);
        else if (a[i].x > q.top().x) {
            q.pop();
            q.push(a[i]);
        }
    while (!q.empty()) {
        ans += q.top().x; q.pop();
    }
    printf("%d", ans);
    return 0;
}