class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        int f[n][m]; memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (A[i] == B[j]) {
                    if (i == 0 || j == 0) f[i][j] = 1;
                    else f[i][j] = f[i - 1][j - 1] + 1;
                    ans = max(ans, f[i][j]);
                }
        return ans;
    }
};