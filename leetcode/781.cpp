class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        if (!n) return 0;
        int nums[1000]; memset(nums, 0, sizeof(nums));
        for (int i = 0; i < n; ++i)
            ++nums[answers[i]];
        int ans = nums[0];
        for (int i = 1; i < 1000; ++i)
            if (nums[i]) {
                int group = nums[i] / (i + 1);
                ans += group * (i + 1);
                if (group * (i + 1) != nums[i])
                    ans += i + 1;
            }
        return ans;
    }
};