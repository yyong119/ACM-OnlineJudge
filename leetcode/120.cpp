class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (!n) return 0;
        if (n == 1) return triangle[0][0];
        for (int i = 1; i < n; ++i) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            for (int j = 1; j < i; ++j)
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i)
            ans = min(ans, triangle[n - 1][i]);
        return ans;
    }
};