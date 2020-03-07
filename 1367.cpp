#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_N 30005
#define MAX_BIT 32
using namespace std;
const int value_bit[MAX_BIT] = {1073741824, 536870912, 268435456, 134217728,
    67108864, 33554432, 16777216, 8388608,
    4194304, 2097152, 1048576, 524288,
    262144, 131072, 65536, 32768,
    16384, 8192, 4096, 2048,
    1024, 512, 256, 128,
    64, 32, 16, 8, 4, 2, 1};
struct Node {
    Node *zero, *one;
}*tree_a, *tree_b;
int num[MAX_BIT];
int n, m, ans;
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
void insert(Node *p, const int& x, int depth) {
    if (depth == MAX_BIT) return;
    if (!(x & value_bit[depth])) {
        if (!p->zero) p->zero = new Node();
        insert(p->zero, x, depth + 1);
    }
    else {
        if (!p->one) p->one = new Node();
        insert(p->one, x, depth + 1);
    }
}
int dfs(Node *p, Node *q, int depth) {
    if (depth == MAX_BIT) return 0;
    int k = 0;
    if (p->zero && q->one)
        k = value_bit[depth] + dfs(p->zero, q->one, depth + 1);
    if (p->one && q->zero)
        k = max(k, value_bit[depth] + dfs(p->one, q->zero, depth + 1));
    if (!k) {
        if (p->zero && q->zero)
            k = dfs(p->zero, q->zero, depth + 1);
        if (p->one && q->one)
            k = max(k, dfs(p->one, q->one, depth + 1));
    }
    return k;
}
int main() {
    n = read(), m = read();
    tree_a = new Node();
    tree_b = new Node();
    for (register int i = 0; i < n; ++i) {
        register int x = read();
        insert(tree_a, x, 0);
    }
    for (register int i = 0; i < m; ++i) {
        register int x = read();
        insert(tree_b, x, 0);
    }
    ans = dfs(tree_a, tree_b, 0);
    printf("%d", ans);
    return 0;
}
