#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX_N 105
#define MAX_M 105
#define MAX_T 6
using namespace std;

struct node {
    int x, y, steps;
    node() : x(0), y(0), steps(0) {}
    node(int p, int q) : x(p), y(q), steps(0) {}
    node(int p, int q, int t) : x(p), y(q), steps(t) {}
}pos_t[MAX_T], st;
const int steps[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, nums, path_dist, ans = 0x3fff3fff;
int a[MAX_N][MAX_M];
int dist[MAX_T][MAX_T];
bool vis[MAX_T];
bool flag, sol = false;

int find_min_dist(node p, node q) {
    queue<node> que; que.push(p);
    bool vis[MAX_N][MAX_M];
    memset(vis, false, sizeof(vis));
    vis[p.x][p.y] = true;

    while (!que.empty()) {
        node cur = que.front(); que.pop();
        for (int i = 0; i < 4; ++i) {
            node next(cur.x + steps[i][0], cur.y + steps[i][1], cur.steps + 1);
            if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m &&
                        a[next.x][next.y] != -1 && !vis[next.x][next.y]) {
                if (next.x == q.x && next.y == q.y)
                    return next.steps;
                que.push(next);
                vis[next.x][next.y] = true;
            }
        }
    }
    return 0x3fff3fff;
}

void dfs(int idx, int depth, int d) {
    if (depth == nums) {
        path_dist = min(path_dist, d);
        flag = true;
        return;
    }
    for (int i = 0; i < nums; ++i)
        if (!vis[i]) {
            vis[i] = true;
            dfs(i, depth + 1, d + dist[idx][i]);
            vis[i] = false;
        }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1) {
                pos_t[nums].x = i; pos_t[nums++].y = j;
            }
            if (a[i][j] == 2) {
                st.x = i; st.y = j;
            }
        }
    for (int i = 0; i < nums - 1; ++i)
        for (int j = 0; j < nums; ++j) {
            if (i == j) continue;
            dist[i][j] = find_min_dist(pos_t[i], pos_t[j]);
            dist[j][i] = dist[i][j];
        }
    for (int i = 0; i < nums; ++i) {
        int length1 = find_min_dist(st, pos_t[i]);
        if (length1 == 0x3fff3fff) continue;
        memset(vis, false, sizeof(vis));
        path_dist = 0x3fff3fff;
        vis[i] = true;
        flag = false;
        dfs(i, 1, 0);
        if (flag) {
            ans = min(ans, length1 + path_dist);
            sol = true;
        }
    }
    if (sol)
        printf("%d\n", ans);
    else
        printf("%d\n", -1);
    return 0;
}