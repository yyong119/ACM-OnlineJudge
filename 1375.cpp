#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 40005
using namespace std;
struct Node {
    int x, y;
    Node(int p = 0, int q = 0): x(p), y(q) {}
} query_seq[MAX_N];
int N, Q, root;
vector<int> link[MAX_N], query[MAX_N];
int ans[MAX_N], father[MAX_N];
bool vis[MAX_N], par[MAX_N];
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
int Find(int x) {
    if (father[x] != x)
        father[x] = Find(father[x]);
    return father[x];
}
void Union(int x, int y) {
    int p = Find(x), q = Find(y);
    father[p] = q;
}
void tarjan(int x) {
    par[x] = true;
    for (register int i = 0; i < link[x].size(); ++i) {
        int next = link[x][i];
        // not the parent node
        if (!par[next]) {
            tarjan(next);
            Union(next, x);
        }
    }
    vis[x] = true;
    // solve the queries
    for (register int i = 0; i < query[x].size(); ++i) {
        int query_id = query[x][i], node_1 = query_seq[query_id].x, node_2 = query_seq[query_id].y;
        if (vis[node_1] && vis[node_2]) {
            int LCA = Find(x == node_1 ? node_2 : node_1);
            if (LCA == node_1) ans[query_id] = 1;
            else if (LCA == node_2) ans[query_id] = 2;
        }
    }
}
int main() {
    // init tree
    N = read();
    for (register int i = 1; i <= MAX_N; ++i) father[i] = i;
    for (register int i = 0; i < N; ++i) {
        int x = read(), y = read();
        if (x != -1 && y != -1) {
            link[x].push_back(y);
            link[y].push_back(x);
        }
        else if (x == -1) root = y;
        else root = x;
    }
    // input queries
    Q = read();
    for (register int i = 0; i < Q; ++i) {
        int x = read(), y = read();
        query_seq[i].x = x;
        query_seq[i].y = y;
        // record the query_id related to the two node
        query[x].push_back(i);
        query[y].push_back(i);
    }
    // find LCA of each query
    tarjan(root);
    // output the answers
    for (register int i = 0; i < Q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
