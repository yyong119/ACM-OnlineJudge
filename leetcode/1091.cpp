class Solution {
public:
    struct node {
        int x, y;
        node(int p, int q) {
            x = p; y = q;
        }
    };
    const int actions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1) return 1;
        if (grid[0][0] || grid[n - 1][m - 1]) return -1;
        grid[0][0] = 1;
        queue<node> q; q.push(node(0, 0));
        while (!q.empty()) {
            node cur = q.front(); q.pop();
            for (int i = 0; i < 8; ++i) {
                node next(cur.x + actions[i][0], cur.y + actions[i][1]);
                if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m &&
                    !grid[next.x][next.y]) {
                        q.push(next);
                        grid[next.x][next.y] = grid[cur.x][cur.y] + 1;
                        if (next.x == n - 1 && next.y == m - 1)
                            return grid[next.x][next.y];
                    }
            }
        }
        if (!grid[n - 1][m - 1]) return -1;
        return grid[n - 1][m - 1];
    }
};