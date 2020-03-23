#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_N 1010
using namespace std;
struct Node {
    int x, candy_assigned;
    Node(int p = 0, int q = 0): x(p), candy_assigned(q) {}
};
int n, m, ans, solved;
vector<int> link[MAX_N];
bool vis[MAX_N];
int in_deg[MAX_N];
queue<Node> q;
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
int main() {
    n = read(), m = read();
    for (register int i = 0; i < m; ++i) {
        int x = read(), y = read();
        ++in_deg[x];
        link[y].push_back(x);
    }
    for (register int i = 1; i <= n; ++i)
        if (!in_deg[i]) q.push(Node(i, 100));
    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        ans += cur.candy_assigned;
        ++solved;
        for (register int i = 0; i < link[cur.x].size(); ++i)
            if (!(--in_deg[link[cur.x][i]]))
                q.push(Node(link[cur.x][i], cur.candy_assigned + 1));
    }
    if (solved == n) printf("%d", ans);
    else printf("hehe");
    return 0;
}
