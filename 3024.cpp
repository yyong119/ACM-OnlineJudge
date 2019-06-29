#include<cstdio>
#include<cstring>
#include<algorithm>
#include <deque>
#define MAX_N 1010
using namespace std;
int n, m;
int f[MAX_N];
int p[MAX_N], w[MAX_N], v[MAX_N];
deque<int> x, y;

void solve() {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < w[i]; ++j){
            x.clear(); y.clear();
            for (int k = 0; j + w[i] * k <= m; ++k) {
                int we = j + w[i] * k, va = v[i] * k;
                if (x.size() == p[i] + 1) {
                    if (y.front() == x.front())
                        y.pop_front();
                    x.pop_front();
                }
                int t = f[we] - va;
                x.push_back(t);
                while (!y.empty() && t >= y.back())
                    y.pop_back();
                y.push_back(t);
                f[we] = y.front() + va;
            }
        }
    }
}

int main() {
    
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", &p[i], &w[i], &v[i]);
    solve();
    printf("%d\n", f[m]);
    return 0;
}