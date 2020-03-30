class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(), sum = 0, l, cur_min = 0x3f3f3f3f;
        for (l = 0; l < len; ++l) {
            sum += nums[l];
            if (sum >= s) {
                cur_min = l + 1;
                break;
            }
        }
        if (cur_min == 0x3f3f3f3f) return 0;
        int r = l; l = 0;
        while (sum - nums[l] >= s)
            sum -= nums[l++];
        cur_min = min(cur_min, r - l + 1);
        while (++r < len) {
            sum += nums[r];
            while (sum - nums[l] >= s)
                sum -= nums[l++];
            cur_min = min(cur_min, r - l + 1);
        }
        return cur_min;
    }
};