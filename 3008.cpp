#include <iostream>
#include <queue>
#define MAX_N 105
using namespace std;
// up, down, left, right
const int ac[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
struct Node {
    int x, y, cnt;
    Node(int p = 0, int q = 0, int k = 0): x(p), y(q), cnt(k) {}
};
int n, m, sx, sy, ex, ey;
int step_cnt[MAX_N][MAX_N];
char map[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
queue<Node> q;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;
    for (register int i = 1; i <= n; ++i)
        for (register int j = 1; j <= m; ++j)
            cin >> map[i][j];
    if (map[ex][ey] == '*') {
        cout << -1;
        return 0;
    }
    // push the start node into queue
    q.push(Node(sx, sy, 0)); vis[sx][sy] = true;
    // bfs
    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        if (cur.x == ex && cur.y == ey) {
            cout << cur.cnt;
            return 0;
        }
        if (map[cur.x][cur.y] == '.')
            for (register int i = 0; i < 4; ++i) {
                int x = cur.x + ac[i][0], y = cur.y + ac[i][1];
                if (x && x <= n && y && y <= m && !vis[x][y] && 
                (map[x][y] == '.' || map[x][y] == '-' && cur.x == x || map[x][y] == '|' && cur.y == y)) {
                    vis[x][y] = true;
                    q.push(Node(x, y, cur.cnt + 1));
                }
            }
        else if (map[cur.x][cur.y] == '-') {
            // go right
            if (cur.y < m && !vis[cur.x][cur.y + 1] && (map[cur.x][cur.y + 1] == '-' || map[cur.x][cur.y + 1] == '.')) {
                vis[cur.x][cur.y + 1] = true;
                q.push(Node(cur.x, cur.y + 1, cur.cnt + 1));
            }
            // go left
            if (cur.y > 1 && !vis[cur.x][cur.y - 1] && (map[cur.x][cur.y - 1] == '-' || map[cur.x][cur.y - 1] == '.')) {
                vis[cur.x][cur.y - 1] = true;
                q.push(Node(cur.x, cur.y - 1, cur.cnt + 1));
            }
        }
        else if (map[cur.x][cur.y] == '|') {
            // go bottom
            if (cur.x < n && !vis[cur.x + 1][cur.y] && (map[cur.x + 1][cur.y] == '|' || map[cur.x + 1][cur.y] == '.')) {
                vis[cur.x + 1][cur.y] = true;
                q.push(Node(cur.x + 1, cur.y, cur.cnt + 1));
            }
            // go up
            if (cur.x > 1 && !vis[cur.x - 1][cur.y] && (map[cur.x - 1][cur.y] == '|' || map[cur.x - 1][cur.y] == '.')) {
                vis[cur.x - 1][cur.y] = true;
                q.push(Node(cur.x - 1, cur.y, cur.cnt + 1));
            }
        }
    }
    cout << -1;
    return 0;
}
