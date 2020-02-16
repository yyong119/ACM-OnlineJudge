#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define MAX_N 505
using namespace std;
struct data {
    int height;
    bool flag;
} a[MAX_N][MAX_N];
struct Node {
    int x, y;
    Node(int p = 0, int q = 0): x(p), y(q) {}
}s;
const int step[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
int n, m, cnt, l, r, rest;
bool vis[MAX_N][MAX_N];
queue<Node> q;
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
inline void clear(queue<Node> &q) {
    queue<Node> empty;
    swap(empty, q);
}
bool check(const int& delta_height) {
    while (!q.empty() && rest) {
        Node cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            Node next(cur.x + step[i][0], cur.y + step[i][1]);
            if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m &&
            !vis[next.x][next.y] && abs(a[next.x][next.y].height - a[cur.x][cur.y].height) <= delta_height) {
                vis[next.x][next.y] = true;
                if (a[next.x][next.y].flag) --rest;
                q.push(next);
            }
        }
    }
    if (rest) return false;
    else return true;
}
int main() {
    n = read(), m = read();
    for (register int i = 0; i < n; ++i)
        for (register int j = 0; j < m; ++j) {
            a[i][j].height = read();
            r = max(r, a[i][j].height);
        }
    for (register int i = 0; i < n; ++i)
        for (register int j = 0; j < m; ++j) a[i][j].flag = read();
    for (register int i = 0; i < n; ++i)
        for (register int j = 0; j < m; ++j)
            if (a[i][j].flag) {
                s.x = i, s.y = j;
                ++cnt;
            }
    l = 0;
    while (l < r) {
        int mid = (l + r) >> 1;
        clear(q); q.push(s);
        memset(vis, false, sizeof(vis)); vis[s.x][s.y] = true;
        rest = cnt - 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d", l);
    return 0;
}