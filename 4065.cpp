#include <cstdio>
#include <queue>
#define MAX_N 305
using namespace std;
struct Node {
    int x, y, cnt;
    Node(int p = 0, int q = 0, int b = 0): x(p), y(q), cnt(b) {
    }
};
const int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int map[MAX_N][MAX_N];
int energy[MAX_N][MAX_N];
queue<Node> q;
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}

int main() {
    n = read(), m = read();
    for (register int i = 0; i < n; ++i)
        for (register int j = 0; j < m; ++j) {
            map[i][j] = read();
            if (map[i][j] == 2) {
                q.push(Node(i, j, 0));
                energy[i][j] = 6;
            }
        }
    register int i;
    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        for (i = 0; i < 4; ++i) {
            int x = cur.x + d[i][0], y = cur.y + d[i][1];
            if (x >= 0 && x < n && y >= 0 && y < m && map[x][y]) {
                // reach destination
                if (map[x][y] == 3) {
                    printf("%d", cur.cnt + 1);
                    return 0;
                }
                // save energy to 6 and not visited
                if (map[x][y] == 4 && !energy[x][y]) {
                    energy[x][y] = 6;
                    q.push(Node(x, y, cur.cnt + 1));
                }
                // map[x][y] can be reached
                // the current solution is better than before that reached [x][y]
                // the energy when reach [x][y] should be at least 2 for further step
                if (map[x][y] == 1 && energy[cur.x][cur.y] - 1 > energy[x][y] && energy[cur.x][cur.y] > 2) {
                    energy[x][y] = energy[cur.x][cur.y] - 1;
                    q.push(Node(x, y, cur.cnt + 1));
                }
            }
        }
    }
    printf("-1");
    return 0;
}
