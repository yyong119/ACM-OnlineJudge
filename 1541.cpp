#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 200010;
struct node {
	int l, r, key;
}tree[MAX_N << 2];
 
void maketree(int node, int l, int r) {
 
	if (l == r) {
		cin >> tree[node].key;
		tree[node].l = l; tree[node].r = r;
		return;
	}
	int mid = (l + r) >> 1;
	maketree(node << 1, l, mid);
	maketree(node << 1 | 1, mid + 1, r);
	tree[node].l = l; tree[node].r = r;
	tree[node].key = max(tree[node << 1].key, tree[node << 1 | 1].key);
}
 
int query(int node, int l, int r) {
 
	if (tree[node].l == l && tree[node].r == r) return tree[node].key;
	int mid = (tree[node].l + tree[node].r) >> 1;
	if (r <= mid) return query(node << 1, l, r);
	else if (l > mid) return query(node << 1 | 1, l, r);
	else return max(query(node << 1, l, mid), query(node << 1 | 1, mid + 1, r));
}
 
int main() {
 
	ios::sync_with_stdio(false);
	int k, n;
	cin >> k >> n;
	maketree(1, 1, n);
	for (int i = 1; i <= n - k + 1; ++i) cout << query(1, i, i + k - 1) << " ";
	return 0;
}