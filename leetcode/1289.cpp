class Solution {
public:
    struct node {
        int id, num;
    };
    static bool cmp(const node& p, const node& q) {
        return p.num < q.num;
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        //init
        int n = arr.size(); if (n == 0) return 0;
        int m = arr[0].size();
        node f[n][m]; memset(f, 0x3f3f3f3f, sizeof(f));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                f[i][j].id = j;
        for (int i = 0; i < m; ++i) f[0][i].num = arr[0][i];
        
        for (int i = 1; i < n; ++i) {
            sort(f[i - 1], f[i - 1] + m, cmp);
            for (int j = 0; j < m; ++j)
                if (f[i - 1][0].id != j)
                    f[i][j].num = f[i - 1][0].num + arr[i][j];
                else f[i][j].num = f[i - 1][1].num + arr[i][j];
        }
        int ans = 0x7fffffff;
        for (int i = 0; i < m; ++i)
            ans = min(ans, f[n - 1][i].num);
        return ans;
    }
};