#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX_N 300005
using namespace std;
struct Node {
    int from, to, weight;
}e[MAX_N];
int n, m, ans;
int f[MAX_N];
vector<int> out_edge[MAX_N];// id of edges that from node x
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
inline bool cmp(const Node &p, const Node &q) {
    return p.weight > q.weight;
}
int dfs(int x) {
    if (f[x]) return f[x];
    int ans = 0, to = e[x].to;
    for (register int i = 0; i < out_edge[to].size(); ++i) 
        if (e[out_edge[to][i]].weight > e[x].weight)
            ans = max(ans, dfs(out_edge[to][i]));
        else break;
    return ans + 1;
}
int main() {
    n = read(), m = read();
    for (register int i = 0; i < m; ++i) {
        int x = read(), y = read(), w = read();
        // out_edge[x].push_back(i);
        e[i].from = x; e[i].to = y; e[i].weight = w;
    }
    sort(e, e + m, cmp);
    for (register int i = 0; i < m; ++i)
        out_edge[e[i].from].push_back(i);
    f[0] = 1; ans = 1;
    for (register int i = 1; i < m; ++i) {
        if (!f[i]) f[i] = dfs(i);
        ans = max(ans, f[i]);
    }
    printf("%d", ans);
    return 0;
}
