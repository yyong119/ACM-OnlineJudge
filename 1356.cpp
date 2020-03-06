#include <cstdio>
#include <vector>
#define MAX_N 100010
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;
struct Node {
    int max_child_id;
    vector<int> child_id;
}tree[MAX_N];
int n, root, q;
vector<int> link_id[MAX_N];
bool vis[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
void build_tree(int x) {
    for (register int i = 0; i < link_id[x].size(); ++i)
        if (!vis[link_id[x][i]]) {// not parent
            vis[link_id[x][i]] = true;
            tree[x].child_id.push_back(link_id[x][i]);
            build_tree(link_id[x][i]);// dfs to build tree
        }
    int cur_max = -1;
    for (register int i = 0; i < tree[x].child_id.size(); ++i) {
        // max of the adjacent child
        cur_max = max(cur_max, tree[x].child_id[i]);
        // sb题目,孩子指直接相连的子节点
        // max of children of the adjacent child
        // cur_max = max(cur_max, tree[tree[x].child_id[i]].max_child_id);
    }
    tree[x].max_child_id = cur_max;
}
int main() {
    n = read(), root = read();
    for (register int i = 1; i < n; ++i) {
        int x = read(), y = read();
        link_id[x].push_back(y);
        link_id[y].push_back(x);
    }
    vis[root] = true;
    build_tree(root);
    q = read();
    while (q--) {
        int x = read();
        printf("%d\n", tree[x].max_child_id);
    }
    return 0;
}