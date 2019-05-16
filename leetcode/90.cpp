class Solution {
public:
    
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int> &nums, int index) {
        
        res.push_back(tmp);
        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            tmp.push_back(nums[i]);
            dfs(nums, i + 1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
};
