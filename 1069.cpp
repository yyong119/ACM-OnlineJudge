#include <cstdio>
#include <cstring>
#define MAX_N 105
#define MAX_M 100005
using namespace std;  
  
int n, m;
int w[MAX_N], c[MAX_N], sum[MAX_M], f[MAX_M];
  
int main() {

    while (~scanf("%d%d", &n, &m)) {

        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; ++i)
            scanf("%d", &w[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &c[i]);

        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 0; i < n; ++i) {
            memset(sum,0,sizeof(sum));
            for (int j = w[i]; j <= m; ++j)
                if(!f[j] && f[j - w[i]] && sum[j - w[i]] < c[i]) {
                    f[j] = 1;
                    sum[j] = sum[j - w[i]] + 1;
                }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i)
            if (f[i])
                ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
