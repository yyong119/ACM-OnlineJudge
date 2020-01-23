class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];
        int f[n]; memset(f, 0, sizeof(f));
        f[0] = nums[0]; f[1] = nums[1];
        for (int i = 2; i < n; ++i)
            for (int j = 0; j < i - 1; ++j)
                f[i] = max(f[i], f[j] + nums[i]);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, f[i]);
        return ans;
    }
};