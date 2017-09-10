#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_N = 35;
struct node {
	node(int a, int b, int p) {
		x = a; y = b; step = p;
	};
	int x, y, step;
};
 
int main() {
 
	int n, m, N, M;
	cin >> n >> m >> N >> M;
	const int movement[8][2] = { {N, M}, {M, N}, {-N, M}, {-M, N}, {-N, -M}, {-M, -N}, {N, -M}, {M, -N} };
	int a[MAX_N][MAX_N]; memset(a, 0, sizeof(a));
	bool visited[MAX_N][MAX_N]; memset(visited, false, sizeof(visited));
	queue<node> que;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] != 1 && a[i][j] != 4) visited[i][j] = true;
			if (a[i][j] == 3) que.push(node(i, j, 0));
		}
	bool found = false;
	int ans;
	while (!que.empty()) {
		node now = que.front();
		for (int i = 0; i < 8; ++i) {
			int nextx = now.x + movement[i][0], nexty = now.y + movement[i][1];
			if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
			if (!visited[nextx][nexty]) {
				if (a[nextx][nexty] == 4) {
					found = true;
					ans = now.step + 1;
					break;
				}
				que.push(node(nextx, nexty, now.step + 1));
				visited[nextx][nexty] = true;
			}
		}
		if (found) break;
		que.pop();
	}
	cout << ans << endl;
	return 0;
}