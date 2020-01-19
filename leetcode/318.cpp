class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (!n) return 0;
        int a[n]; memset(a, 0, sizeof(a));
        int len[n]; memset(len, 0, sizeof(len));
        for (int i = 0; i < n; ++i) len[i] = words[i].length();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < len[i]; ++j) {
                int idx = words[i][j] - 'a';
                if (!((a[i] >> idx) & 1))
                    a[i] += 1 << idx;
            }
        
        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if (!(a[i] & a[j])) ans = max(ans, len[i] * len[j]);
        return ans;
    }
};
