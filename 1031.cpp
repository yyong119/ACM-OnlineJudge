#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_N = 100;
const int m[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
int n, minh, maxh;
int map[MAX_N + 1][MAX_N + 1];
bool isVisited[MAX_N + 1][MAX_N + 1];
struct node {
	int x, y;
};
 
bool findpath(const int& MIND, const int& MAXD) {
 
	if (map[1][1] > MAXD || map[1][1] < MIND || map[n][n] > MAXD || map[n][n] < MIND) return false;
	
	queue<node> que;
	node now, next;
	while (que.size()) que.pop();
	memset(isVisited, false, sizeof(isVisited));
	que.push({ 1, 1 });
 
	while (!que.empty()) {
		now = que.front(); que.pop();
		isVisited[now.x][now.y] = true;
		for (int i = 0; i < 4; ++i) {
			next.x = now.x + m[i][0]; next.y = now.y + m[i][1];
			if ((next.x > 0)&&(next.x <= n)&&(next.y > 0)&&(next.y <= n) && (!isVisited[next.x][next.y]) && (map[next.x][next.y] >= MIND) && (map[next.x][next.y] <= MAXD)) {
				if ((next.x == n)&&(next.y == n)) return true;
				que.push(next);
				isVisited[next.x][next.y] = true;
			}
		}
	}
 
	return false;
}
 
int main() {
 
	cin >> n;
	minh = 120; maxh = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			maxh = (map[i][j] > maxh) ? map[i][j] : maxh;
			minh = (map[i][j] < minh) ? map[i][j] : minh;
		}
	int l = 0, r = maxh - minh;
	while (l < r) {
		int mid = (l + r) >> 1;
		bool flag = false;
		for (int i = minh; i <= maxh - mid; ++i)
			if (findpath(i, i + mid)) {
				flag = true;
				break;
		}
		if (flag) r = mid; else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}