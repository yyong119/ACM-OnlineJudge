class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            if (nums[i] >= 10 && nums[i] < 100 || nums[i] >= 1000 && nums[i] < 10000)
                ++ans;
        return ans;
    }
};