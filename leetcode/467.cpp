class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (!p.length()) return 0;
        int k = 1;
        int f[26]; memset(f, 0, sizeof(f));
        f[p[0] - 'a'] = 1;
        for (int i = 1; i < p.length(); ++i) {
            if (p[i] - 1 == p[i - 1] || p[i] == 'a' && p[i - 1] == 'z')
                ++k;
            else
                k = 1;
            f[p[i] - 'a'] = max(f[p[i] - 'a'], k);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) ans += f[i];
        return ans;
    }
};
