int maxheight;
class Solution {
public:
    void dfs(vector<int> &rods, int idx, int l, int r, int left, const int &n) {
        if (abs(l - r) > left || l + r + left <= (maxheight << 1))
            return;
        if (l == r) maxheight = max(maxheight, l);
        if (++idx == n) return;
        left -= rods[idx];
        dfs(rods, idx, l + rods[idx], r, left, n);
        dfs(rods, idx, l, r + rods[idx], left, n);
        dfs(rods, idx, l, r, left, n);
    }
    int tallestBillboard(vector<int>& rods) {
        if (rods.size() < 2) return 0;
        int n = rods.size(), sum = 0;
        for (int i = 0; i < n; ++i) sum += rods[i];
        maxheight = 0;
        sort(rods.begin(), rods.end(), greater<int>());
        dfs(rods, 0, rods[0], 0, sum - rods[0], n);
        dfs(rods, 0, 0, 0, sum - rods[0], n);
        return maxheight;
    }
};
