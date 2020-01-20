class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        int nums[k][2]; memset(nums, 0, sizeof(nums));
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < strs[i].length(); ++j)
                ++nums[i][strs[i][j] - '0'];
        int f[m + 1][n + 1]; memset(f, 0, sizeof(f));
        f[0][0] = 1;
        int ans = 1;
        for (int i = 0; i < k; ++i)
            for (int M = m; M >= nums[i][0]; --M)
                for (int N = n; N >= nums[i][1]; --N)
                    if (f[M - nums[i][0]][N - nums[i][1]]) {
                        f[M][N] = max(f[M][N], f[M - nums[i][0]][N - nums[i][1]] + 1);
                        ans = max(ans, f[M][N]);
                    }
        return ans - 1;
    }
};
