class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int len = A.size();
        if (!len) return 0;
        unordered_map<int, int> dp[len];
        int ans = 1;
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < i; ++j) {
                int diff = A[i] - A[j];
                if (dp[j][diff]) dp[i][diff] = dp[j][diff] + 1;
                else dp[i][diff] = 2;
                ans = max(dp[i][diff], ans);
            }
        return ans;
    }
};