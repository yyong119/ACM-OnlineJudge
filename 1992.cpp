#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_N 10010
using namespace std;

struct node{
    int l, r;
} a[MAX_N];
int n, cnt;

inline bool cmp(node p, node q) {
    return p.l < q.l;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i].l, &a[i].r);
    sort(a, a + n, cmp);
    int upd = 0, cur_l = a[0].l, cur_r = a[0].r;
    for (int i = 1; i < n; ++i) {
        if (a[i].r <= cur_r) continue;
        if (a[i].l > cur_r) {
            cnt += cur_r - cur_l;
            cur_l = a[i].l;
        }
        cur_r = a[i].r;
    }
    cnt += cur_r - cur_l;
    printf("%d\n", cnt);
    return 0;
}