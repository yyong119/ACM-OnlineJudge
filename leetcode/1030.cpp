class Solution {
public:

    const int action[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {

        bool flag[R][C]; memset(flag, false, sizeof(flag));
        queue<vector<int>> que;
        vector<vector<int>> ans;
        vector<int> cur = {r0, c0}, next = {0, 0};

        que.push(cur);
        flag[r0][c0] = true;
        while (!que.empty()) {
            cur = que.front(); que.pop(); ans.push_back(cur);
            for (int i = 0; i < 4; ++i) {
                next[0] = cur[0] + action[i][0];
                next[1] = cur[1] + action[i][1];
                if (next[0] >= 0 && next[0] < R && next[1] >= 0 && next[1] < C &&
                    flag[next[0]][next[1]] == false) {
                        que.push(next);
                        flag[next[0]][next[1]] = true;
                    }
            }
        }

        return ans;
    }
};