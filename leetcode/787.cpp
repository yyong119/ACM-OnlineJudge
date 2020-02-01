class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        K = min(K, n - 2);
        vector<int> dp(n, 0x3f3f3f3f);
        dp[src] = 0;
        for (int k = 0; k <= K; ++k) {
            vector<int> dp1 = dp;
            for (auto& e: flights)
                dp1[e[1]] = min(dp1[e[1]], dp[e[0]] + e[2]);
            swap(dp1, dp);
        }
        if (dp[dst] == 0x3f3f3f3f) return -1;
        return dp[dst];
    }
};
