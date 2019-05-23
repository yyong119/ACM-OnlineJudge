#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX_N 100010
using namespace std;

struct node{
    int d, t;
}a[MAX_N];
int n, ans;
int sum[MAX_N];

inline bool cmp(node p, node q) {
    return p.t > q.t;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i].d, &a[i].t);
    sort(a, a + n, cmp);
    priority_queue<int, vector<int>, less<int> > que;
    int idx = 0;
    for (int t_end = a[0].t - 1; t_end >= 0; --t_end) {
        while(a[idx].t > t_end && idx < n)
            que.push(a[idx++].d);
        if (!que.empty()) {
            ans += que.top();
            que.pop();
        }
    }
    printf("%d\n", ans);
    return 0;
}
