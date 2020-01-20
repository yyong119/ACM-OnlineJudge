class Solution {
public:
    struct Node {
        int x, y, k, steps;
        Node(int p = 0, int q = 0, int r = 0, int s = 0) : x(p), y(q), k(r), steps(s) {}
    };
    const int actions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        bool visited[n][m][k + 1]; memset(visited, false, sizeof(visited));
        visited[0][0][0] = true;
        queue<Node> q; q.push(Node(0, 0, 0, 0));
        while (!q.empty()) {
            Node cur = q.front(); q.pop();
            if (cur.x == n - 1 && cur.y == m - 1) return cur.steps;
            // cout << cur.x << " " << cur.y << " " << cur.steps << endl;
            for (int i = 0; i < 4; ++i) {
                int x = cur.x + actions[i][0], y = cur.y + actions[i][1];
                if (x >= 0 && x < n && y >= 0 && y < m)
                    if (grid[x][y] == 0 && !visited[x][y][cur.k]) {
                        q.push(Node(x, y, cur.k, cur.steps + 1));
                        visited[x][y][cur.k] = true;
                    }
                    else if (grid[x][y] == 1 && cur.k < k && !visited[x][y][cur.k + 1]) {
                        q.push(Node(x, y, cur.k + 1, cur.steps + 1));
                        visited[x][y][cur.k + 1] = true;
                    }
            }
        }
        return -1;
    }
};
