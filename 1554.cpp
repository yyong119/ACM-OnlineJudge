#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 800010
#define INF 0x7fffffff

struct node {
	int fpoint, tpoint, cost;
	node(int p, int q, int cc) {
		fpoint = p; tpoint = q; cost = cc;
	};
	node() {
		fpoint = 0; tpoint = 0; cost = 0;
	};
}tree[MAX_N << 1];
 
int start_index[MAX_N], par[MAX_N];
long f[MAX_N];
bool visited[MAX_N];
 
inline bool cmp(node p, node q) {
	return p.fpoint != q.fpoint ? p.fpoint < q.fpoint : p.tpoint < q.tpoint;
}

int main() {

	int n, root;
	scanf("%d%d", &n, &root);

	for (int i = 1; i < n; ++i) {
		int temp1, temp2, co;
		scanf("%d%d%d", &temp1, &temp2, &co);
		tree[i] = node(temp1, temp2, co);
		tree[i + n - 1] = node(temp2, temp1, co);
	}
	tree[(n << 1) - 1] = node(root, 0, INF);

	// In ascending order
	sort(tree + 1, tree + (n << 1), cmp);
	// Mark the start_index index of each node
	for (int i = (n << 1) - 1; i > 0; --i)
		start_index[tree[i].fpoint] = i;
	start_index[n + 1] = n << 1;

	visited[0] = true;
	queue<int> que;
	que.push(root);
	while (!que.empty()) {
		int cur = que.front(); que.pop();
		visited[cur] = true;
		// Indexes of cur
		for (int i = start_index[cur]; i < start_index[cur + 1]; ++i) {
			int next = tree[i].tpoint;
			if (visited[next]) // next is parent
				par[cur] = next;
			else { // next is child
				par[next] = cur;
				que.push(next);
			}
		}
	}

	memset(visited, false, sizeof(visited));
	visited[0] = true;

	stack<int> sta;
	sta.push(root); que.push(root);
	while (!que.empty()) {

		int cur = que.front(); que.pop();
		visited[cur] = true;
		// Indexes of node cur
		for (int i = start_index[cur]; i < start_index[cur + 1]; ++i)
			if (!visited[tree[i].tpoint]) {
				que.push(tree[i].tpoint);
				sta.push(tree[i].tpoint);
				visited[tree[i].tpoint] = true;
			}
	}

	while (!sta.empty()) {
		int cur = sta.top(); sta.pop();
		// Leaf node
		if (start_index[cur + 1] - start_index[cur] == 1)
			f[cur] = tree[start_index[cur]].cost;
		else {
			for (int i = start_index[cur]; i < start_index[cur + 1]; ++i)
				f[cur] += f[tree[i].tpoint] < tree[i].cost ? f[tree[i].tpoint] : tree[i].cost;
		}
	}

	printf("%d\n", f[root]);
	return 0;
}