#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int MAX_N = 110;
struct Node{
	int lc, rc;
	int val;
};
Node tree[MAX_N];
int m, n;
int arr[MAX_N][MAX_N];
int f[MAX_N][MAX_N];
bool vis[MAX_N];
 
void Create(int root) {
 
	vis[root] = true;
	for (int i = 1; i <= m; ++i) {
		if (!vis[i] && arr[root][i]) {
			if (!tree[root].lc) tree[root].lc = i;
			else tree[root].rc = i;
			tree[i].val = arr[root][i];
			Create(i);
		}
	}
}
 
int TreeDP(int root, int e) {
 
	if (root == 0 || e == 0) return 0;
	if (f[root][e]) return f[root][e];
	int maxx = 0, l, r;
	for (int i = 0; i < e; ++i) {
		l = TreeDP(tree[root].lc, i);
		r = TreeDP(tree[root].rc, e - i - 1);
		maxx = max(l + r, maxx);
	}
	f[root][e] = maxx + tree[root].val;
	return f[root][e];
}
 
int main() {
 
	ios::sync_with_stdio(false);
	cin >> m >> n;
	int from, to, value;
	for (int i = 1; i < m; ++i) {
		cin >> from >> to >> value;
		arr[to][from] = arr[from][to] = value;
	}
	Create(1);
	cout << TreeDP(1, ++n) << endl;
	return 0;
}