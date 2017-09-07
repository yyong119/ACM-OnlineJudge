#include <cstdio>
#include <vector>
#include <algorithm>
#define M 100011
using namespace std;
 
inline int read()
{
	char ch; int ret = 0;
	for (ch = getchar(); ch<'0' || ch>'9'; ch = getchar());
	for (; ch >= '0'&& ch <= '9'; ret = ret * 10 + ch - '0', ch = getchar());
	return ret;
}
 
vector<int> G[M];
int anc[18][M] = { 0 }, que[M], dep[M] = { 0 };
bool visit[M] = { 0 };
 
int find_LCA(int a, int b) {
	if (a == b) return a;
	for (int k = 17; k >= 0; --k) if (anc[k][a] != anc[k][b]) a = anc[k][a], b = anc[k][b];
	return anc[0][a];
}
 
void maintain(int & a, int & b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = 17; k >= 0; --k) if (dep[anc[k][a]] >= dep[b]) a = anc[k][a];
	//for (int d = dep[a] - dep[b], i = 0; d; d >>= 1, ++i) if (d & 1) a = anc[i][a];
}
 
int main() {
 
	//int n = read(), q = read(), x, y;
	int n, q, x, y;
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i) {
		//x = read(), y = read();
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int front = 1, rear = 1;
	que[1] = 1, dep[1] = 1, visit[1] = true;
	while (front <= rear) {
		x = que[front];
		for (int i = 0; i < G[x].size(); ++i) {
			if (visit[G[x][i]]) continue;
			visit[G[x][i]] = true;
			que[++rear] = G[x][i];
			dep[G[x][i]] = dep[x] + 1;
			anc[0][G[x][i]] = x;
			for (int j = 1; j <= 17; ++j) {
				anc[j][G[x][i]] = anc[j - 1][anc[j - 1][G[x][i]]];
			}
		}
		++front;
	}
	for (int i = 1; i <= q; ++i) {
		//x = read(), y = read();
		scanf("%d%d", &x, &y);
		if (dep[x] != dep[y]) maintain(x, y);
		printf("%d\n", find_LCA(x, y));
	}
	return 0;
}