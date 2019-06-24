#include <cstdio>
using namespace std;
const int MAX_N = 100001;
int tree[MAX_N << 2];
 
void update(int t, int l, int r, int point) {
 
    ++tree[t];
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (point <= mid)
        update(t << 1, l, mid, point);
    else
        update(t << 1 | 1, mid + 1, r, point);
}
 
int query(int t, int l, int r, int ql, int qr) {
 
    if (l == ql && r == qr) return tree[t];
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(t << 1, l, mid, ql, qr);
    else if (ql > mid)
        return query(t << 1 | 1, mid + 1, r, ql, qr);
    else
        return query(t << 1, l, mid, ql, mid) + query(t << 1 | 1, mid + 1, r, mid + 1, qr);
}
 
int main() {
 
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        update(1, 1, n, tmp);
    }
    for (int i = 0; i < m; ++i) {
        int tmpl, tmpr;
        scanf("%d%d", &tmpl, &tmpr);
        printf("%d\n", query(1, 1, n, tmpl, tmpr));
    }
    return 0;
}
