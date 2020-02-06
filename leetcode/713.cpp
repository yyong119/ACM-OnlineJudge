class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        if (!n || !k) return 0;
        int l = 0, prod = nums[0];
        if (prod < k) ans = 1;
        for (register int r = 1; r < n; ++r) {
            prod *= nums[r];
            while (l < r &&prod >= k) prod /= nums[l++];
            if (prod < k)
                ans += r - l + 1;
        }
        return ans;
    }
};