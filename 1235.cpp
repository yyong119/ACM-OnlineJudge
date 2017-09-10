#include <iostream>
#include <queue>
#define INF 1 << 30
using namespace std;
 
const int MAX_N = 10010;
struct node{
	queue<int> p, c;
}a[MAX_N];
int n, m, startp, endp;
int dist[MAX_N], pre[MAX_N];
bool inque[MAX_N];
 
int main() {
	
	ios::sync_with_stdio(false);
	cin >> n >> m >> startp >> endp;
	for (int i = 1; i <= m; ++i) {
		int fromp, top, cost;
		cin >> fromp >> top >> cost;
		a[fromp].p.push(top);
		a[fromp].c.push(cost);
	}
	for (int i = 1; i <= n; ++i) {
		dist[i] = INF;
		pre[i] = i;
	}
	dist[startp] = 0;
 
	queue<int> que;
	que.push(startp); inque[startp] = true;
	while (!que.empty()) {
		int now = que.front();
		queue<int> tmpp = a[now].p, tmpc = a[now].c;
		while (!tmpp.empty()) {
			int nextp = tmpp.front(), nextc = tmpc.front();
			if (dist[nextp] > dist[now] + nextc) {
				dist[nextp] = dist[now] + nextc;
				pre[nextp] = now;
				if (!inque[nextp]) {
					que.push(nextp);
					inque[nextp] = true;
				}
			}
			tmpp.pop(); tmpc.pop();
		}
		que.pop(); inque[now] = false;
	}
	cout << dist[endp] << endl << startp;
 
	int line[MAX_N], t = 1;
	line[1] = endp;
	while (pre[line[t]] != startp) line[++t] = pre[line[t - 1]];
	for (int i = t; i > 0; --i) cout << " " << line[i];
 
	return 0;
}