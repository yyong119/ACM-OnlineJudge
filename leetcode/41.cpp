class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 1;
        for (int i = 0; i < n; ++i)
            if (nums[i] > n || nums[i] < 0) nums[i] = 0;
        for (int i = 0; i < n; ++i)
            if (nums[i] % (n << 1) > 0 || nums[i] == n)
                nums[nums[i] % n] += n << 1;
        
        for (int i = 1; i < n; ++i)
            if (nums[i] <= n) return i;
        if (nums[0] < n) return n;
        return n + 1;
    }
};