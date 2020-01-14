class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int p[n << 1 | 1]; memset(p, 0x3f3f3f3f, sizeof(p));
        int cnt = n, ans = 0;
        p[n] = -1;
        for (int i = 0; i < n; ++i) {
            --cnt += nums[i] << 1;
            if (p[cnt] == 0x3f3f3f3f) p[cnt] = i;
            else ans = max(ans, i - p[cnt]);
        }
        return ans;
    }
};