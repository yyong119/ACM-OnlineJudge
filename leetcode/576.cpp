class Solution {
public:
    const long long MOD = 1e9 + 7;
    int findPaths(int m, int n, int N, int i, int j) {
        if (!N) return 0;
        long long f[m + 2][n + 2][N + 1]; memset(f, 0, sizeof(f));
        f[++i][++j][0] = 1;
        long long ans = (i == 1) + (i == m) + (j == 1) + (j == n);

        for (int steps = 1; steps < N; ++steps) {
            for (int x = 1; x <= m; ++x)
                for (int y = 1; y <= n; ++y) {
                    f[x - 1][y][steps] += f[x][y][steps - 1];
                    f[x + 1][y][steps] += f[x][y][steps - 1];
                    f[x][y - 1][steps] += f[x][y][steps - 1];
                    f[x][y + 1][steps] += f[x][y][steps - 1];
                }
            for (int x = 1; x <= m; ++x)
                for (int y = 1; y <= n; ++y)
                    if (f[x][y][steps] >= MOD) f[x][y][steps] %= MOD;
            for (int y = 1; y <= n; ++y) ans += f[1][y][steps] + f[m][y][steps];
            for (int x = 1; x <= m; ++x) ans += f[x][1][steps] + f[x][n][steps];
            ans %= MOD;
        }
        return ans;
    }
};
