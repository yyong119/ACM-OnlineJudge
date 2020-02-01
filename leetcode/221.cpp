class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size();
        int f[n][m]; memset(f, 0, sizeof(f));
        for (int i = 0; i < m; ++i) f[0][i] = matrix[0][i] - '0';
        for (int i = 0; i < n; ++i) f[i][0] = matrix[i][0] - '0';
        int ans = 0;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (matrix[i][j] == '1') {
                    f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]);
                    f[i][j] = min(f[i][j], f[i][j - 1]);
                    ++f[i][j];
                }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) ans = max(ans, f[i][j]);
        return ans * ans;
    }
};
