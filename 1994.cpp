#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_N 505
using namespace std;
struct Node {
    int x, y;
    Node(int p = 0, int q = 0): x(p), y(q) {}
};
const int ac[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, cnt;
int map[MAX_N][MAX_N];
queue<Node> q;
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
int main() {
    n = read(), m = read();
    for (register int i = 0; i < n; ++i)
        for (register int j = 0; j < m; ++j)
            map[i][j] = read();
    for (register int i = 0; i < n; ++i)
        for (register int j = 0; j < m; ++j)
            if (!map[i][j]) {
                ++cnt;
                q.push(Node(i, j)); map[i][j] = 1;
                while (!q.empty()) {
                    Node cur = q.front(); q.pop();
                    for (register int k = 0; k < 4; ++k) {
                        int x = cur.x + ac[k][0], y = cur.y + ac[k][1];
                        if (x >= 0 && x < n && y >= 0 && y < m && !map[x][y]) {
                            map[x][y] = 1;
                            q.push(Node(x, y));
                        }
                    }
                }
            }
    printf("%d", cnt);
    return 0;
}
