#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_N 20010
#define INF 0xfffffff
using namespace std;

int distA[MAX_N], distB[MAX_N], distC[MAX_N];
int n, a, b, c, ans = INF, pos = 0;
vector<int> point[MAX_N], length[MAX_N];

void solve(int origin, int dist[]) {

	for (int i = 1; i <= n; ++i) dist[i] = INF;
	dist[origin] = 0;

	bool flag[n]; memset(flag, false, sizeof(flag));
	queue<int> q; while(!q.empty()) q.pop();

	q.push(origin); flag[origin] = true;
	while (!q.empty()) {
		int now = q.front(); 
		q.pop(); flag[now] = false;
		for (int i = 0; i < point[now].size(); ++i) {
			int next = point[now][i];
			if (dist[next] > dist[now] + length[now][i]) {
				dist[next] = dist[now] + length[now][i];
				if (flag[next] == false) {
					q.push(next);
					flag[next] = true;
				}
			}
		}
	}
}

int main() {

	scanf("%d%d%d%d", &n, &a, &b, &c);
	for (int i = 1; i < n; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		point[u].push_back(v); length[u].push_back(w);
		point[v].push_back(u); length[v].push_back(w);
	}
	solve(a, distA);
	solve(b, distB);
	solve(c, distC);
	for (int i = n; i > 0; --i)
		if (distA[i] + distB[i] + distC[i] <= ans) {
			ans = distA[i] + distB[i] + distC[i];
			pos = i;
		}
	// for (int i = 1; i <= n; ++i) printf("%d ", distA[i]); printf("\n");
	// for (int i = 1; i <= n; ++i) printf("%d ", distB[i]); printf("\n");
	// for (int i = 1; i <= n; ++i) printf("%d ", distC[i]); printf("\n");
	printf("%d\n%d\n", pos, ans);
	return 0;
}
