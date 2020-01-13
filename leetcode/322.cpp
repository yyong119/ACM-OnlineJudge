class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount) return 0;
        int n = coins.size();
        int f[amount + 5]; memset(f, 0x3f3f3f3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i <= amount; ++i)
            for (int j = 0; j < n; ++j)
                if (i - coins[j] >= 0)
                    f[i] = min(f[i], f[i - coins[j]] + 1);
        if (f[amount] != 0x3f3f3f3f)
            return f[amount];
        else
            return -1;
    }
};