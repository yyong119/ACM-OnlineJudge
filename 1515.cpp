#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct node {
	node(int a, int b, int p) {
		x = a; y = b; step = p;
	};
	int x, y, step;
};
const int MAX_N = 1001;
const int movement[4][2] = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
int map[MAX_N][MAX_N], map1[MAX_N][MAX_N], map2[MAX_N][MAX_N];
bool isVisited[MAX_N][MAX_N];
 
int  main() {
	int n, m, mincost = 0xFFFFFF;
	int sx, sy, ex, ey;
	queue<node> umb;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 4) umb.push(node(i, j, 0));
			else if (map[i][j] == 2) { sx = i; sy = j; }
			else if (map[i][j] == 3) { ex = i; ey = j; }
		}
 
	queue<node> que; que.push(node(sx, sy, 0)); isVisited[sx][sy] = true;
	while (!que.empty()) {
		node now = que.front();
		for (int i = 0; i < 4; ++i) {
			node next(now.x + movement[i][0], now.y + movement[i][1], now.step + 1);
			if (next.x < 1 || next.x > m || next.y < 1 || next.y > n) continue;
			if (map[next.x][next.y] != 1 && !isVisited[next.x][next.y]) {
				que.push(next);
				isVisited[next.x][next.y] = true;
				map1[next.x][next.y] = next.step;
			}
		}
		que.pop();
	}
 
	memset(isVisited, false, sizeof(isVisited));
	que.push(node(ex, ey, 0)); isVisited[ex][ey] = true;
	while (!que.empty()) {
		node now = que.front();
		for (int i = 0; i < 4; ++i) {
			node next(now.x + movement[i][0], now.y + movement[i][1], now.step + 1);
			if (next.x < 1 || next.x > m || next.y < 1 || next.y > n) continue;
			if (map[next.x][next.y] != 1 && !isVisited[next.x][next.y]) {
				que.push(next);
				isVisited[next.x][next.y] = true;
				map2[next.x][next.y] = next.step;
			}
		}
		que.pop();
	}
 
	while (!umb.empty()) {
		node tmp = umb.front(); umb.pop();
		if (map1[tmp.x][tmp.y] + map2[tmp.x][tmp.y] < mincost && map1[tmp.x][tmp.y] + map2[tmp.x][tmp.y])
			mincost = map1[tmp.x][tmp.y] + map2[tmp.x][tmp.y];
	}
 
	cout << mincost << endl;
	return 0;
}