class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int nums[26]; memset(nums, 0, sizeof(nums));
        for (int i = 0; i < text.length(); ++i)
            ++nums[text[i] - 'a'];
        int ans = 0x7fffffff;
        ans = min(ans, nums['a' - 'a']);
        ans = min(ans, nums['b' - 'a']);
        ans = min(ans, nums['l' - 'a'] >> 1);
        ans = min(ans, nums['n' - 'a']);
        ans = min(ans, nums['o' - 'a'] >> 1);
        return ans;
    }
};