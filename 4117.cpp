#include <iostream>
#include <cstdio>
#define MAX_N 100010
using namespace std;

long long tree[MAX_N << 2];
int flag[MAX_N << 2];
 
void buildtree(int idx, int l, int r) {
    if (l == r) {
        scanf("%lld", &tree[idx]);
        return;
    }
    int mid = (l + r) >> 1;
    buildtree(idx << 1, l, mid);
    buildtree(idx << 1 | 1, mid + 1, r);
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}
 
void pushdown(int idx, int l, int r) {
    int mid = (l + r) >> 1;
    tree[idx << 1] += (long long) flag[idx] * (mid - l + 1);
    tree[idx << 1 | 1] += (long long) flag[idx] * (r - mid);
    flag[idx << 1] += flag[idx];
    flag[idx << 1 | 1] += flag[idx];
    flag[idx] = 0;
}
 
void add(int idx, int l, int r, int a, int b, int c) {
    if (l == a && b == r) {
        tree[idx] += (long long)c * (b - a + 1);
        flag[idx] += c;
        return;
    }
    if (flag[idx])
        pushdown(idx, l, r);
    int mid = (l + r) >> 1;
    if (b <= mid)
        add(idx << 1, l, mid, a, b, c);
    else if (a > mid) 
        add(idx << 1 | 1, mid + 1, r, a, b, c);
    else {
        add(idx << 1, l, mid, a, mid, c);
        add(idx << 1 | 1, mid + 1, r, mid + 1, b, c);
    }
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}
 
long long query(int idx, int l, int r, int a, int b) {
    if (l == a && r == b)
        return tree[idx];
    int mid = (l + r) >> 1;
    if (flag[idx])
        pushdown(idx, l, r);
    if (b <= mid)
        return query(idx << 1, l, mid, a, b);
    else if (a > mid)
        return query(idx << 1 | 1, mid + 1, r, a, b);
    else
        return query(idx << 1, l, mid, a, mid) + query(idx << 1 | 1, mid + 1, r, mid + 1, b);
}
 
int main() {
 
    int n, m;
    scanf("%d%d", &n, &m);
    buildtree(1, 1, n);
    while (m--) {
        char op[2]; scanf("%s", op);
        if (op[0] == 'Q') {
            int a, b; scanf("%d%d", &a, &b);
            printf("%lld\n", query(1, 1, n, a, b));
        }
        else {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            add(1, 1, n, a, b, c);
        }
    }
    return 0;
}
