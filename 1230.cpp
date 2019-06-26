#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAX_N 2010
using namespace std;

int a[MAX_N];
int dp[MAX_N][MAX_N];
int w[MAX_N][MAX_N];
int n, m;

int main() {

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            w[i][j] = w[i][j - 1] + a[j] - a[(i + j) >> 1];

    memset(dp, INF, sizeof(dp));
    //dp[i][j]前i位建j个仓库
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = w[1][i];
        dp[i][i] = 0;
    }

    // for (int i = 1; i <= n; ++i) //末仓库位置 
    //     for (int j = 2; j <= min(m, i); ++j) //仓库数
    //         for(int k = i - 1; k >= j - 1 && w[k + 1][i] < dp[i][j];--k) //k到i建1仓库
    //以上注释可过80分,区别仅在ij层循环次序
    //比赛碰到就随缘80或100吧
    for (int i = 2; i <= m; ++i) //仓库数
        for (int j = i + 1; j <= n - m + i; ++j) //末仓库位置
            for (int k = j - 1; k >= i - 1 && w[k + 1][j] < dp[j][i]; --k) //k到j建1仓库
                dp[j][i] = min(dp[j][i], dp[k][i - 1] + w[k + 1][j]);
    
    printf("%d\n", dp[n][m]);
    return 0;
}
