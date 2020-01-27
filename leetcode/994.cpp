class Solution {
public:
    struct Node {
        int x, y, d;
        Node(int p, int q, int a) : x(p), y(q), d(a) {}
    };
    const int actions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        queue<Node> q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 2) q.push(Node(i, j, 0));
                else if (grid[i][j]) ++cnt;
        if (!cnt) return 0;
        while (!q.empty()) {
            Node cur = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = cur.x + actions[i][0], y = cur.y + actions[i][1];
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                    if (!(--cnt)) return cur.d + 1;
                    grid[x][y] = 2;
                    q.push(Node(x, y, cur.d + 1));
                }
            }
        }
        return -1;
    }
};
