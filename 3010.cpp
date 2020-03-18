#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX_N 30010
using namespace std;
int n, m, cnt;
int in[MAX_N], ans[MAX_N];
vector<int> link_node[MAX_N];
priority_queue<int, vector<int>, greater<int> > q;
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
    for (register int i = 1; i <= n; ++i) {
        m = read();
        for (register int j = 0; j < m; ++j) {
            int tmp = read();
            link_node[i].push_back(tmp);
            ++in[tmp];
        }
    }
    for (register int i = 1; i <= n; ++i)
        if (!in[i]) q.push(i);
    while (!q.empty()) {
        int cur = q.top(); q.pop();
        ans[++cnt] = cur;
        for (register int i = 0; i < link_node[cur].size(); ++i) {
            int tmp = link_node[cur][i];
            if (!(--in[tmp]))
                q.push(tmp);
        }
    }
    if (cnt != n) printf("no solution");
    else {
        printf("%d\n", n);
        for (register int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
    }
    return 0;
}
