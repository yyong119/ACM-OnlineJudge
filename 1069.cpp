#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;  
  
int n, m;
int w[105], c[105], sum[100005], dp[100005];
  
int main() {

    while (~scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            memset(sum,0,sizeof(sum));
            for (int j = w[i]; j <= m; ++j)
                if(!dp[j] && dp[j - w[i]] && sum[j - w[i]] < c[i]) {
                    dp[j] = 1;
                    sum[j] = sum[j - w[i]] + 1;
                    ++ans;
                }
        }
        printf("%d\n", ans);
    }
    return 0;
}
