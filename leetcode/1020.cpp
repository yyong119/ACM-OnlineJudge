class Solution {
public:
    struct Node {
        int x, y;
        Node(int p = 0, int q = 0) :x(p), y(q) {}
    };
    const int actions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int numEnclaves(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        queue<Node> q;
        for (int i = 0; i < m; ++i) {
            if (A[0][i]) q.push(Node(0, i));
            if (A[n - 1][i]) q.push(Node(n - 1, i));
        }
        for (int i = 0; i < n; ++i) {
            if (A[i][0]) q.push(Node(i, 0));
            if (A[i][m - 1]) q.push(Node(i, m - 1));
        }
        while (!q.empty()) {
            Node cur = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = cur.x + actions[i][0], y = cur.y + actions[i][1];
                if (x > 0 && x < n - 1 && y > 0 && y < m - 1 && A[x][y]) {
                    A[x][y] = 0;
                    q.push(Node(x, y));
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < n - 1; ++i)
            for (int j = 1; j < m - 1; ++j)
                ans += A[i][j];
        return ans;
    }
};
