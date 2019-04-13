class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= nums[l]) {
                if (target <= nums[mid] && target >= nums[l])
                    r = mid;
                else l = mid + 1;
            }
            else {
                if (target >= nums[l] || target <= nums[mid])
                    r = mid;
                else l = mid + 1;
            }
        }
        if (l == r && nums[r] == target) return r;
        return -1;
    }
};