#include <iostream>
#include <algorithm>
#define MAX_N 100010
using namespace std;

struct node {
    int x, l;
} a[MAX_N];
int n, cnt, cur_p;

inline bool cmp(node p, node q) {
    return p.x + p.l < q.x + q.l;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].l;
    sort(a, a + n, cmp);
    cur_p = a[0].x + a[0].l;
    cnt = 1;
    for (int i = 1; i < n; ++i)
        if (a[i].x - a[i].l > cur_p) {
            cur_p = a[i].x + a[i].l;
            ++cnt;
        }
    cout << cnt << endl;
    return 0;
}
