#include <cstdio>
#include <iostream>
 
using namespace std;
 
const int movement[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int data[501][501], f[501][501];
int n, m, longest;
 
int dfs(int x, int y) {
 
    int nx, ny, maxx = 0;
 
    if (f[x][y]) return f[x][y];
    for (int i = 0; i <= 3; i++) {
        nx = x + movement[i][0];
        ny = y + movement[i][1];
        if ((nx > 0) && (ny > 0) && (nx <= n) && (ny <= m) && (data[nx][ny] < data[x][y]))
            maxx = max(maxx, dfs(nx, ny));
    }
    f[x][y] = maxx + 1;
    return f[x][y];
}
 
int main() {
 
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &data[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = dfs(i, j);
            longest = max(longest, f[i][j]);
        }
    printf("%d\n", longest);
    return 0;
}