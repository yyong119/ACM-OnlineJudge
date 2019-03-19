class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int pre_max = 0, cur_max = nums[0], n = nums.size();
        if (n <= 1) return true;
        
        while (cur_max < n - 1) {
            
            int i = pre_max;
            pre_max = cur_max;
            for (; i <= pre_max; ++i)
                cur_max = max(cur_max, nums[i] + i);
            if (pre_max == cur_max && cur_max != n) return false;
        }
        return true;
    }
};