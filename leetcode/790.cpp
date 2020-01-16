class Solution {
public:
    int numTilings(int N) {
        long long dp[N + 5]; memset(dp, 0, sizeof(dp));
        int mod = 1e9 + 7;
        dp[0] = 1; dp[1] = 1; dp[2] = 2;

        for(int i = 3; i <= N; ++i)
            // dp[i] = (2*(dp[i - 1] % mod) % mod + dp[i - 3] % mod) % mod;
            dp[i] = ((dp[i - 1] << 1) + dp[i - 3]) % mod;
        return (int)dp[N];
    }
};