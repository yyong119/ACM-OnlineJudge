class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length(), ans = 0;
        // first idea to check each alphabet individually
        // for (int i = 0; i < 26; ++i) {
        //     char cur = 'A' + i;
        //     int l = 0, cnt = 0;
        //     for (int r = 0; r < len; ++r) {
        //         if (s[r] == cur) ++cnt;
        //         else while(cnt + k < r - l + 1)
        //                 if (s[l++] == cur) --cnt;
        //         ans = max(ans, r - l + 1);
        //     }
        // }
        // better idea with only one scan
        int cnt[26]; memset(cnt, 0, sizeof(cnt));
        int l = 0, max_cnt = 0;
        for (int r = 0; r < len; ++r) {
            ++cnt[s[r] - 'A'];
            max_cnt = max(max_cnt, cnt[s[r] - 'A']);// only the last one may change the max count
            while (max_cnt + k < r - l + 1)
                --cnt[s[l++] - 'A'];// move the left pointer right
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};