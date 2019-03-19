class Solution {
public:
    
    vector<vector<int>> res;
    int n;
    
    void get_permute(int depth, vector<int> nums, bool chosen[], vector<int> ans) {
        
        if (depth == n)
            res.push_back(ans);
        else {
            for (int i = 0; i < n; ++i)
                if (!chosen[i]) {
                    chosen[i] = true;
                    ans[depth] = nums[i];
                    get_permute(depth + 1, nums, chosen, ans);
                    chosen[i] = false;
                }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        n = nums.size();
        if (n == 0) return res;
        bool chosen[n];
        memset(chosen, false, sizeof(chosen));
        vector<int> tmp(n);
        get_permute(0, nums, chosen, tmp);
        return res;
    }
};