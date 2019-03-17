class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int cur_max = nums[0], steps = 1, pre = 0;
        
        while (cur_max < n - 1) {
            int tmp_max = 0;
            for (int i = pre; i <= cur_max; ++i)
                tmp_max = max(tmp_max, nums[i] + i);
            pre = cur_max;
            cur_max = tmp_max;
            ++steps;
        }
        return steps;
    }
};