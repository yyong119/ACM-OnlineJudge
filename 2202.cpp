#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int movement[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAX_N = 1000;
struct posdata {
	posdata(int a, int b, bool p) {
		x = a; y = b; cross = p;
	};
	int x, y;
	bool cross = false;
};
int a[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
 
int main() {
 
	int k; cin >> k;
	while (k--) {
 
		int n, m;
		cin >> n >> m;
		memset(a, 0, sizeof(a));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> a[i][j];
		bool found = false;
		queue<posdata> que; while(!que.empty()) que.pop();
		que.push(posdata(0, 0, false)); visited[0][0] = true;
		
		while (!que.empty()) {
 
			posdata now = que.front();
 
			for (int i = 0; i < 4; ++i) {
				posdata next(now.x + movement[i][0], now.y + movement[i][1], now.cross);
				if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
				if (next.x == n - 1 && next.y == m - 1) {
					found = true;
					break;
				}
				switch (a[next.x][next.y]) {
					case 0:
						if (!visited[next.x][next.y]) {
							que.push(next);
							visited[next.x][next.y] = true;
						}
						break;
					case 1:
						if (!next.cross) {
							next.cross = true;
							que.push(next);
							visited[next.x][next.y] = true;
						}
						break;
				}
			}
			if (found) break;
			que.pop();
		}
		if (found) cout << 1 << endl; else cout << 0 << endl;
	}
	return 0;
}