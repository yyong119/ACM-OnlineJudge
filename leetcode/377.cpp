class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) return 0;
        double f[target + 1 + *max_element(nums.begin(), nums.end())];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 0; i < target; ++i)
            for (int j = 0; j < n; ++j)
                f[i + nums[j]] += f[i];
        return (int)f[target];
    }
};