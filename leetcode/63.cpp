class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        if (m == 0) return 0;
        if (obstacleGrid[0][0] || obstacleGrid[n - 1][m - 1]) return 0;
        vector<long long> dp(m, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (obstacleGrid[i][j])
                    dp[j] = 0;
                else if (j > 0)
                    dp[j] += dp[j-1];
        return dp[m - 1];
    }
};