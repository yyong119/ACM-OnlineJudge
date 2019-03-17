class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size(), zero_cut = n - 1;
        
        for (int i = 0; i < n; ++i)
            if (nums[i] > 0) {
                zero_cut = i;
                break;
            }
        for (int i = 0; i < zero_cut; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r)
                if (nums[i] + nums[l] + nums[r] == 0) {
                    vector<int> ans = {nums[i], nums[l++], nums[r--]};
                    while (nums[l] == nums[l - 1] && l < r) ++l;
                    while (nums[r] == nums[r + 1] && l < r) --r;
                    res.push_back(ans);
                }
                else if (nums[i] + nums[l] + nums[r] < 0)
                    while (nums[++l] == nums[l - 1] && l < r);
                else while (nums[--r] == nums[r + 1] && l < r);
        }
        return res;
    }
};