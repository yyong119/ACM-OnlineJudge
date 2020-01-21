class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        int f[sum + 1]; memset(f, 0, sizeof(f));
        int cur_max = nums[0];
        f[cur_max] = 1;
        for (int i = 1; i < n; ++i) {
            cur_max += nums[i];
            for (int j = cur_max; j >= nums[i]; --j)
                if (f[j - nums[i]]) f[j] = 1;
        }
        if (sum % 2 == 0 && f[sum >> 1]) return true;
        return false;
    }
};
