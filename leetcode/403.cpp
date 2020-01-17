class Solution {
public:
    bool find(vector<int>& stones, int l, int r, int target, int &idx) {
        while (l < r) {
            int mid = (l + r) >> 1;
            if (stones[mid] == target) {
                idx = mid;
                return true;
            }
            else if (stones[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        if (l == r && l < stones.size() && stones[l] == target) {
            idx = l;
            return true;
        }
        return false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size(), m = stones[n - 1];
        if (n == 1) return true;
        if (stones[1] != 1) return false;
        // only when the 2nd stone is 1 can be true
        bool f[n + 1][n + 1]; memset(f, false, sizeof(f));
        f[1][1] = true;
        for (int i = 1; i < n - 1; ++i)
            for (int j = 1; j < n; ++j)
                if (f[i][j]) { //can reach ith stone by j steps
                    int idx;
                    for (int k = j - 1; k <= j + 1; ++k)
                        if (find(stones, i + 1, n, stones[i] + k, idx))
                            f[idx][k] = true;
                }
        // for (int i = 1; i < n; ++i) {
        //     for (int j = 1; j < n; ++j) cout << f[i][j] << " ";
        //     cout << endl;
        // }
        for (int i = 1; i < n; ++i)
            if (f[n - 1][i])
                return true;
        return false;
    }
};