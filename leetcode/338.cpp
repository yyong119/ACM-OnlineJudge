class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> cnt(num + 1, 0);
        for (register int i = 1; i <= num; ++i)
            cnt[i] = cnt[i >> 1] + ((i & -i) == 1);
        return cnt;
    }
};