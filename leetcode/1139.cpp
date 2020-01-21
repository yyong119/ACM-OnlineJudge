class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        int rows[n + 1][m + 1], columns[n + 1][m + 1];
        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));

        for (int i = 0; i < n; ++i)
            for (int j = m - 1; j >= 0; --j)
                if (grid[i][j]) rows[i][j] = rows[i][j + 1] + 1;
                else rows[i][j] = 0;
        for (int j = 0; j < m; ++j)
            for (int i = n - 1; i >= 0; --i)
                if (grid[i][j]) columns[i][j] = columns[i + 1][j] + 1;
                else columns[i][j] = 0;
        int ans = 0;
        for (int i = 0; i < n - ans; ++i)
            for (int j = 0; j < m - ans; ++j)
                for (int k = min(rows[i][j], columns[i][j]); k > ans; --k)
                    if (columns[i][j + k - 1] >= k && rows[i + k - 1][j] >= k) {
                        ans = k;
                        break;
                    }
        return ans * ans;
    }
};
