#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX_N 100010
using namespace std;
struct Node {
    int value, day;
    bool operator <(const Node &p) const { return value > p.value; }
} a[MAX_N];
int n;
long long ans;
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
inline bool cmp(const Node &p, const Node &q) {
    return p.day < q.day;
}

int main() {
    n = read();
    for (register int i = 0; i < n; ++i) {
        a[i].day = read(); a[i].value = read();
    }
    sort(a, a + n, cmp);
    priority_queue<Node> q;
    q.push(a[0]);
    for (register int i = 1; i < n; ++i) {
        if (a[i].day <= q.size()) {
            if (a[i].value > q.top().value) {
                q.pop(); q.push(a[i]);
            }
        }
        else q.push(a[i]);
    }
    while (!q.empty()) {
        ans += (long long)q.top().value;
        q.pop();
    }
    printf("%lld\n", ans);
    return 0;
}
