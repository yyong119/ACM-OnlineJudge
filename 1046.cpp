#include <cstdio>
#define MAX_N 100010
using namespace std;
int n, p, q, root;
struct Node {
    int par, ls, rs, size, red, color;// color == 1 means red
} tree[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
void build_tree_size(int x) {
    if (!tree[x].ls && !tree[x].rs) {
        tree[x].size = 1;
        return;
    }
    if (tree[x].ls) build_tree_size(tree[x].ls);
    if (tree[x].rs) build_tree_size(tree[x].rs);
    tree[x].size = tree[tree[x].ls].size + tree[tree[x].rs].size + 1;
}
void push_up(int x) {
    ++tree[x].red;
    if (tree[x].par) push_up(tree[x].par);
}
void dye(int x, int num) {
    int l_size = tree[tree[x].ls].size;
    // just node x
    if (num == l_size + 1) {
        // haven't been dyed to red
        if (!tree[x].color) {
            tree[x].color = 1;
            // red size for each parent of x(including x) increase 1
            push_up(x);
        }
        return;
    }
    // at left part
    if (num <= l_size) dye(tree[x].ls, num);
    // at right part
    if (num > l_size + 1) dye(tree[x].rs, num - l_size - 1);
}
int main() {
    n = read(), p = read(), q = read();
    // input tree structure
    for (register int i = 0; i < n; ++i) {
        int par = read(), ls = read(), rs = read();
        tree[par].ls = ls; tree[par].rs = rs;
        tree[ls].par = par; tree[rs].par = par;
    }
    // find root
    for (register int i = 1; i <= n; ++i)
        if (!tree[i].par) {
            root = i; break;
        }
    // get size of each node
    build_tree_size(root);
    // for (int x = 1; x <= n; ++x)
    //     printf("%d ", tree[x].size);
    // printf("\n");
    // dye red color
    while (p--) {
        int x = read(), t = read();
        dye(x, t % tree[x].size + 1);
    }
    // query number of red color
    while (q--) {
        int x = read();
        printf("%d\n", tree[x].red);
    }
    return 0;
}
