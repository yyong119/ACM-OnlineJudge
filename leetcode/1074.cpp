class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int sum[n][m];
        sum[0][0] = matrix[0][0];
        for (int i = 1; i < m; ++i) sum[0][i] = sum[0][i - 1] + matrix[0][i];
        for (int i = 1; i < n; ++i) {
            sum[i][0] = sum[i - 1][0] + matrix[i][0];
            for (int j = 1; j < m; ++j)
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + matrix[i][j] - sum[i - 1][j - 1];
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) cout << sum[i][j] << " ";
        //     cout << endl;
        // }

        unordered_map<int, int> cnt;
        int ans = 0, cur_sum;
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j) {
                cnt.clear();
                for (int k = 0; k < m; ++k) {
                    if (!i) cur_sum = sum[j][k];
                    else cur_sum = sum[j][k] - sum[i - 1][k];
                    // cout << "i="<<i <<" j="<<j<<" k="<<k<<" sum="<<cur_sum<<endl;
                    if (cur_sum == target) ++ans;
                    if (cnt.find(cur_sum - target) != cnt.end())
                        ans += cnt[cur_sum - target];
                    ++cnt[cur_sum];
                    // cout << ans<<endl;
                }
            }
        return ans;
    }
};
/*
0 1 0
1 1 1
0 1 0
*/
