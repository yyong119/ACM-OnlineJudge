class Solution {
public:
    
    void get_permutations(vector<int> nums, int depth, int n, vector<vector<int>> &res){
        
        if (depth == n - 1) res.push_back(nums);
        else {
            
            get_permutations(nums, depth + 1, n, res);
            
            for (int i = depth + 1; i < n; ++i)
                if (nums[i] != nums[depth]) {
                    swap(nums[i], nums[depth]);
                    get_permutations(nums, depth + 1, n, res);
                }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> res;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        get_permutations(nums, 0, n, res);
        
        return res;
    }
};