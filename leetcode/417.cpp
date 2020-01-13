class Solution {
public:
    const int actions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        // init
        vector<vector<int>> ans;
        int n = matrix.size();
        if (!n) return ans;
        int m = matrix[0].size();
        if (!m) return ans;
        bool lu[n][m], rb[n][m];
        memset(lu, false, sizeof(lu)); memset(rb, false, sizeof(rb));
        // solve left up side
        vector<int> cur = {0, 0}, next = {0, 0};
        queue<vector<int>> q;
        cur[0] = 0;
        for (int i = 0; i < m; ++i) {
            cur[1] = i; q.push(cur);
        }
        cur[1] = 0;
        for (int i = 0; i < n; ++i) {
            cur[0] = i; q.push(cur);
        }
        while(!q.empty()) {
            cur = q.front(); q.pop();
            lu[cur[0]][cur[1]] = true;
            for (int i = 0; i < 4; ++i) {
                next[0] = cur[0] + actions[i][0];
                next[1] = cur[1] + actions[i][1];
                if (next[0] >= 0 && next[0] < n && next[1] >= 0 && next[1] < m &&
                matrix[next[0]][next[1]] >= matrix[cur[0]][cur[1]] &&
                !lu[next[0]][next[1]]) {
                    q.push(next);
                }
            }
        }
        // solve right bottom side
        cur[0] = n - 1;
        for (int i = 0; i < m; ++i) {
            cur[1] = i; q.push(cur);
        }
        cur[1] = m - 1;
        for (int i = 0; i < n; ++i) {
            cur[0] = i; q.push(cur);
        }
        while(!q.empty()) {
            cur = q.front(); q.pop();
            rb[cur[0]][cur[1]] = true;
            for (int i = 0; i < 4; ++i) {
                next[0] = cur[0] + actions[i][0];
                next[1] = cur[1] + actions[i][1];
                if (next[0] >= 0 && next[0] < n && next[1] >= 0 && next[1] < m &&
                matrix[next[0]][next[1]] >= matrix[cur[0]][cur[1]] &&
                !rb[next[0]][next[1]]) {
                    q.push(next);
                }
            }
        }
        // compare
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (lu[i][j] && rb[i][j]) {
                    cur[0] = i; cur[1] = j;
                    ans.push_back(cur);
                }
        return ans;
    }
};