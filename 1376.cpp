#include <cstdio>
using namespace std;
const int MAX_N = 100010;
struct node {
	int l, r;
	long long key;
}tree[MAX_N << 2];
 
void buildtree(int node, int l, int r) {
 
	if (l == r) {
		scanf("%lld", &tree[node].key);
		tree[node].l = l; tree[node].r = r;
		return;
	}
	int mid = (l + r) >> 1;
	buildtree(node << 1, l, mid);
	buildtree(node << 1 | 1, mid + 1, r);
	tree[node].l = l; tree[node].r = r;
	tree[node].key = tree[node << 1].key + tree[node << 1 | 1].key;
}
 
void update(int node, int pos,int key) {
 
	if (tree[node].l == tree[node].r) {
		tree[node].key = key;
		return;
	}
	int mid = (tree[node].l + tree[node].r) >> 1;
	if (pos <= mid) update(node << 1, pos, key);
	else update(node << 1 | 1, pos, key);
	tree[node].key = tree[node << 1].key + tree[node << 1 | 1].key;
}
 
long long query(int node, int l, int r) {
 
	if (tree[node].l == l && tree[node].r == r) return tree[node].key;
	int mid = (tree[node].l + tree[node].r) >> 1;
	if (r <= mid) return query(node << 1, l, r);
	else if (l > mid) return query(node << 1 | 1, l, r);
	else return query(node << 1, l, mid) + query(node << 1 | 1, mid + 1, r);
}
 
int main() {
 
	int n; scanf("%d", &n);
	buildtree(1, 1, n);
	int m; scanf("%d", &m);
	while (m--) {
		int op, tmp1, tmp2;
		scanf("%d%d%d", &op, &tmp1, &tmp2);
		if (op == 2) printf("%lld\n", query(1, tmp1, tmp2));
		else update(1, tmp1, tmp2);
	}
	return 0;
}