class Solution {
public:
    const int MAX_N = 80000;
    int minIncrementForUnique(vector<int>& A) {
        int f[MAX_N + 5]; memset(f, 0, sizeof(f));
        int n = A.size();
        if (n == 0 || n == 1) return 0;
        int h = 0x7fffffff, t = 0;
        for (int i = 0; i < n; ++i) {
            ++f[A[i]];
            h = min(h, A[i]);
            t = max(t, A[i]);
        }
        int e = h + 1;
        int solved = 1, ans = 0;
        while (h <= t) {
            while (f[h] > 1) {
                cout << h << " ";
                e = max(h, e);
                while (f[e]) ++e;
                cout << e << endl;
                ans += e - h;
                --f[h];
                ++e;
            }
            ++h;
        }
        return ans;
    }
};