const int MOD = 1e9 + 7;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].length();
        board[n - 1][m - 1] = '0';
        int f[n][m]; memset(f, -1, sizeof(f));
        long long nums[n][m]; memset(nums, 0, sizeof(nums));
        nums[0][0] = 1; f[0][0] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] != 'X' && f[i][j] != -1) {
                    if (j < m - 1 && board[i][j + 1] != 'X') {
                        int r = board[i][j + 1] - '0';
                        if (f[i][j] + r > f[i][j + 1]) {
                            f[i][j + 1] = f[i][j] + r;
                            nums[i][j + 1] = nums[i][j];
                        }
                        else if (f[i][j] + r == f[i][j + 1]) {
                            nums[i][j + 1] += nums[i][j];
                            nums[i][j + 1] %= MOD;
                        }
                    }
                    if (i < n - 1 && board[i + 1][j] != 'X') {
                        int b = board[i + 1][j] - '0';
                        if (f[i][j] + b > f[i + 1][j]) {
                            f[i + 1][j] = f[i][j] + b;
                            nums[i + 1][j] = nums[i][j];
                        }
                        else if (f[i][j] + b == f[i + 1][j]) {
                            nums[i + 1][j] += nums[i][j];
                            nums[i + 1][j] %= MOD;
                        }
                    }
                    if (i < n - 1 && j < m - 1 && board[i + 1][j + 1] != 'X') {
                        int rb = board[i + 1][j + 1] - '0';
                        if (f[i][j] + rb > f[i + 1][j + 1]) {
                            f[i + 1][j + 1] = f[i][j] + rb;
                            nums[i + 1][j + 1] = nums[i][j];
                        }
                        else if (f[i][j] + rb == f[i + 1][j + 1]) {
                            nums[i + 1][j + 1] += nums[i][j];
                            nums[i + 1][j + 1] %= MOD;
                        }
                    }
                }
        vector<int> ans(2, 0);
        if (f[n - 1][m - 1] != -1) {
            ans[0] = f[n - 1][m - 1];
            ans[1] = nums[n - 1][m - 1];
        }
        return ans;
    }
};