class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size(), idx = n - 1;
        if (n == 1 || n == 0) return;
        for (; idx > 0; --idx)
            if (nums[idx - 1] < nums[idx]) {
                --idx;
                break;
            }

        if (idx == 0 && nums[0] >= nums[1]) {
            sort(nums.begin(), nums.end());
        }
        else {
            int min_num = 0x3fff3fff, min_idx, s;
            for (int i = idx + 1; i < n; ++i)
                if (nums[i] > nums[idx] && nums[i] < min_num) {
                    min_num = nums[i];
                    min_idx = i;
                }
            // cout << min_idx << " " << min_num << endl;
            s = nums[idx]; nums[idx] = nums[min_idx]; nums[min_idx] = s;
            // for (int i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
            // cout << endl;       
            sort(nums.begin() + idx + 1, nums.end());
        }
    }
};