class Solution {
public:
    int firstUniqChar(string s) {
        int sums[26]; memset(sums, 0, sizeof(sums));
        int len = s.length();
        for (int i = 0; i < len; ++i)
            ++sums[s[i] - 'a'];
        for (int i = 0; i < len; ++i)
            if (sums[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
