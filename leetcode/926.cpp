class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.length();
        int previous_1[n + 5], following_0[n + 5]; // n : 0 ~ n - 1
        memset(previous_1, 0, sizeof(previous_1));
        memset(following_0, 0, sizeof(following_0));
        for (int i = 1; i <= n; ++i)
            if (S[i - 1] == '1') previous_1[i] = previous_1[i - 1] + 1;
            else previous_1[i] = previous_1[i - 1];
        for (int i = n - 1; i >= 0; --i)
            if (S[i] == '0') following_0[i] = following_0[i + 1] + 1;
            else following_0[i] = following_0[i + 1];
        // for(int i = 0; i <= n; ++i)
        //     cout << previous_1[i] << " " << following_0[i] << endl;
        int ans = n;
        for (int i = 0; i <= n; ++i)
            ans = min(ans, previous_1[i] + following_0[i]);
        return ans;
    }
};
