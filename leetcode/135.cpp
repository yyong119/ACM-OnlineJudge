class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1) return 1;
        int sugars[n]; memset(sugars, 0, sizeof(sugars));
        // calc the minimums
        if (ratings[0] <= ratings[1]) sugars[0] = 1;
        if (ratings[n - 1] <= ratings[n - 2]) sugars[n - 1] = 1;
        for (int i = 1; i < n - 1; ++i)
            if (ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1])
                sugars[i] = 1;
        // from left to right
        for (int i = 1; i < n; ++i)
            if (!sugars[i] && sugars[i - 1] && ratings[i] > ratings[i - 1]) sugars[i] = sugars[i - 1] + 1;
        // from right to left
        for (int i = n - 2; i >= 0; --i)
            if (ratings[i] > ratings[i + 1]) sugars[i] = max(sugars[i], sugars[i + 1] + 1);

        int ans = 0;
        for (int i = 0; i < n; ++i) ans += sugars[i];
        return ans;
    }
};