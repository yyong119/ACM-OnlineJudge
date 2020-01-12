class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[200];
        for (int i = 0; i < 200; ++i) pos[i] = -1;
        int len = s.length();
        int max_len = 0, cur_len = 0;
        for (int i = 0; i < len; ++i) {
            int id = s[i];
            if (pos[id] == -1) {
                ++cur_len;
                pos[id] = i;
            }
            else {
                max_len = max(max_len, cur_len);
                cur_len = min(cur_len + 1, i - pos[id]);
                pos[id] = i;
            }
        }
        max_len = max(max_len, cur_len);
        return max_len;
    }
};