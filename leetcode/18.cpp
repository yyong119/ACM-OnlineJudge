class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = n - 1;
        if (n < 4) return res;
        for (int l = 0; l < n - 3; ++l) {
            
            if (l && nums[l] == nums[l - 1]) continue;
            for (int r = n - 1; r > l + 2; --r) {
                
                if (r < n - 1 && nums[r] == nums[r + 1]) continue;
                int sum = nums[l] + nums[r], ll = l + 1, rr = r - 1;

                while (ll < rr)
                    if (sum + nums[ll] + nums[rr] == target) {
                        vector<int> ans = {nums[l], nums[ll++], nums[rr--], nums[r]};
                        res.push_back(ans);
                        while (ll < rr && nums[ll] == nums[ll - 1]) ++ll;
                        while (rr > ll && nums[rr] == nums[rr + 1]) --rr;
                    }
                    else if (sum + nums[ll] + nums[rr] < target) 
                        while (ll < rr && sum + nums[ll] + nums[rr] < target) ++ll;
                    else
                        while (ll < rr && sum + nums[ll] + nums[rr] > target) --rr;

            }
        }
        return res;
    }
};