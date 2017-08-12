#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int MAX_N = 800001;
const long INF = 1 << 30;
struct node {
	int fpoint, tpoint, cost;
	node(int p, int q, int cc) {
		fpoint = p; tpoint = q; cost = cc;
	};
	node() {
		fpoint = 0; tpoint = 0; cost = 0;
	};
}tree[MAX_N << 1];
 
int start[MAX_N], pre[MAX_N];
long f[MAX_N];
bool visited[MAX_N];
 
inline bool cmp(node p, node q) {
	return p.fpoint != q.fpoint ? p.fpoint < q.fpoint : p.tpoint < q.tpoint;
}
 
int main() {
 
	ios::sync_with_stdio(false);
	int n, root;
	cin >> n >> root;
	for (int i = 1; i < n; ++i) {
 
		int temp1, temp2, co;
		cin >> temp1 >> temp2 >> co;
		tree[i] = node(temp1, temp2, co);
		tree[i + n - 1] = node(temp2, temp1, co);
	}
	tree[2 * n - 1] = node(root, 0, INF);
 
	sort(tree + 1, tree + 2 * n, cmp);
	for (int i = 2 * n - 1; i > 0; --i) start[tree[i].fpoint] = i;
	start[n + 1] = 2 * n;
 
	visited[0] = true;
 
	queue<int> que; que.push(root);
	while (!que.empty()) {
 
		int now = que.front(); visited[now] = true;
		for (int i = start[now]; i < start[now + 1]; ++i) {
			int next = tree[i].tpoint;
			if (visited[next]) pre[now] = next;
			else {
				pre[next] = now;
				que.push(next);
			}
		}
		que.pop();
	}
 
	memset(visited, false, sizeof(visited)); visited[0] = true;
 
	stack<int> sta;
	sta.push(root); que.push(root);
	while (!que.empty()) {
 
		int now = que.front(); visited[now] = true;
		for (int i = start[now]; i < start[now + 1]; ++i) {
			if (!visited[tree[i].tpoint]) {
				que.push(tree[i].tpoint);
				sta.push(tree[i].tpoint);
				visited[tree[i].tpoint] = true;
			}
		}
		que.pop();
	}
 
	while (!sta.empty()) {
		int now = sta.top(); sta.pop();
		if (start[now + 1] - start[now] == 1)
			f[now] = tree[start[now]].cost;
		else {
			for (int i = start[now]; i < start[now + 1]; ++i)
				f[now] += f[tree[i].tpoint] < tree[i].cost ? f[tree[i].tpoint] : tree[i].cost;
		}
	}
	cout << f[root] << endl;
	return 0;
}