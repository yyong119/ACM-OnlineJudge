class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        if (n == 0 || n == 1) return dominoes;
        int a[n]; memset(a, 0, sizeof(a));
        for (int i = 0; i < n; ++i)
            if (dominoes[i] == 'L') a[i] = -1;
            else if (dominoes[i] == 'R') a[i] = 1;

        int t = -1;
        for (int i = 0; i < n; ++i) //push right
            if (a[i] == -1) t = -1;
            else if (a[i] == 1) t = 1;
            else if (a[i] == 0 && t > 0) a[i] = ++t;

        t = -1;
        for (int i = n - 1; i >= 0; --i) //push left
            if (a[i] == 1) t = -1;
            else if (a[i] == -1) t = 1;
            else if (t > 0) {
                ++t;
                if (a[i] == 0 || a[i] > t) a[i] = -t;
                if (a[i] == t) a[i] = 0;
            }
            
        char ans[n + 5];
        ans[n] = '\0';
        for (int i = 0; i < n; ++i)
            if (a[i] == 0) ans[i] = '.';
            else if (a[i] > 0) ans[i] = 'R';
            else ans[i] = 'L';
        return ans;
    }
};