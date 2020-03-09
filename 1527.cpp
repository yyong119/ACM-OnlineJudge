#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX_N 510
#define MAX_M 1030

using namespace std;

int f, x, id_min = 0x3f3f3f3f, id_max = 0, cnt;
int map[MAX_N][MAX_N], degree[MAX_M], ans[MAX_M];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
void dfs(int u) {
    for (register int i = id_min; i <= id_max; ++i)
        if (map[u][i]) {
            --map[u][i];
            --map[i][u];
            dfs(i);
        }
    ans[++cnt] = u;
}

int main() {
    f = read();
    for (register int i = 0; i < f; ++i) {
        int a = read(), b = read();
        if (a < b) {
            id_min = min(a, id_min);
            id_max = max(b, id_max);
        }
        else {
            id_min = min(b, id_min);
            id_max = max(a, id_max);
        }
        ++degree[a]; ++degree[b];
        ++map[a][b]; ++map[b][a];
    }
    x = id_min;
    for (register int i = id_min; i <= id_max; ++i)
        if (degree[i] & 1) {
            x = i;
            break;
        }
    dfs(x);
    for (register int i = cnt; i; --i) printf("%d\n", ans[i]);
    return 0;
}