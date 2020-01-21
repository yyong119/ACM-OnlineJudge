class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int f[n + 1], cnt[n + 1];
        for (int i = 0; i < n; ++i) {
            f[i] = 1;
            cnt[i] = 1;
        }
        int max_len = 1;
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        cnt[i] = cnt[j];
                        max_len = max(max_len, f[i]);
                    }
                    else if (f[i] == f[j] + 1)
                        cnt[i] += cnt[j];
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (f[i] == max_len)
                ans += cnt[i];
        return ans;
    }
};
