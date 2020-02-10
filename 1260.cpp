#include <cstdio>
#define MAX_N 300010
using namespace std;
struct Node {
    int pos, num;
} a[MAX_N];
int n;
int tree[MAX_N << 2];
int ans[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1;
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
void build_tree(int x, int l, int r) {
    tree[x] = r - l + 1;
    if (l != r) {
        int mid = (l + r) >> 1;
        build_tree(x << 1, l, mid);
        build_tree(x << 1 | 1, mid + 1, r);
    }
}
int query(int x, int l, int r, int pos) {
    if (l == r) {
        tree[x] = 0;
        while (x) {
            x >>= 1; --tree[x];
        }
        return l;
    }
    // printf("%d %d %d %d\n",l, r, tree[x << 1], tree[x << 1 | 1]);
    int mid = (l + r) >> 1;
    if (tree[x << 1] >= pos) return query(x << 1, l, mid, pos);
    else return query(x << 1 | 1, mid + 1, r, pos - tree[x << 1]);
}
int main() {
    n = read();
    build_tree(1, 1, n);
    for (register int i = 0; i < n; ++i) {
        a[i].pos = read(); a[i].num = read();
    }
    for (register int i = n - 1; i >= 0; --i) {
        int k = query(1, 1, n, a[i].pos + 1);
        // printf("##%d\n", k);
        ans[k] = a[i].num;
    }
    for (register int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    return 0;
}
