class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int f1[n], f2[n];
        memset(f1, 0, sizeof(f1));
        memset(f2, 0, sizeof(f2));
        // 0 ~ n - 2
        f1[0] = nums[0];
        f1[1] = nums[1];
        for (int i = 2; i < n - 1; ++i)
            for (int j = 0; j < i - 1; ++j)
                f1[i] = max(f1[i], f1[j] + nums[i]);
        // 1 ~ n - 1
        f2[1] = nums[1];
        f2[2] = nums[2];
        for (int i = 3; i < n; ++i)
            for (int j = 1; j < i - 1; ++j)
                f2[i] = max(f2[i], f2[j] + nums[i]);
        
        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, f1[i]);
        for (int i = 0; i < n; ++i) ans = max(ans, f2[i]);
        return ans;
    }
};
