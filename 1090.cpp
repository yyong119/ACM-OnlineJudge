#include <iostream>
#include <cstdio>
#include <climits>
#define MAX_S 100020
#define MAX_N 105
using namespace std;
int n, ans;
int s[MAX_N], f[MAX_N];
int dp[MAX_S << 1];
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
int main() {
    n = read();
    for (int i = 0; i < n; ++i) {
        s[i] = read(); f[i] = read();
    }
    for (int i = 0; i < (MAX_S << 1); ++i) dp[i] = INT_MIN;
    dp[MAX_S] = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] <= 0 && f[i] <= 0)
            continue;
        if (s[i] > 0) {
            for (register int j = (MAX_S << 1) - 1; j >= s[i]; --j)
                if (dp[j - s[i]] > INT_MIN && dp[j - s[i]] + f[i] > dp[j])
                    dp[j] = dp[j - s[i]] + f[i];
        }
        else {
            for (register int j = 0; j < (MAX_S << 1) + s[i]; ++j)
                if (dp[j - s[i]] > INT_MIN && dp[j - s[i]] + f[i] > dp[j])
                    dp[j] = dp[j - s[i]] + f[i];
        }
    }
    for (register int i = MAX_S; i < (MAX_S << 1); ++i)
        if (dp[i] >= 0)
            ans = max(ans, dp[i] + i - MAX_S);
    printf("%d\n", ans);
    return 0;
}
