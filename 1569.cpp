#include <iostream>
using namespace std;
const int MAX_N = 10010;
struct node {
	int l, r, key;
}tree[MAX_N << 1];
 
void buildtree(int node, int l, int r) {
 
	if (l == r) {
		tree[node].l = l; tree[node].r = r;
		cin >> tree[node].key;
		return;
	}
	int mid = (l + r) >> 1;
	buildtree(node << 1, l, mid);
	buildtree(node << 1 | 1, mid + 1, r);
	tree[node].l = l; tree[node].r = r;
	tree[node].key = tree[node << 1].key + tree[node << 1 | 1].key;
}
 
void inc(int node, int pos, int key) {
 
	if (tree[node].l == tree[node].r) {
		tree[node].key += key;
		return;
	}
	int mid = (tree[node].l + tree[node].r) >> 1;
	if (pos > mid) inc(node << 1 | 1, pos, key);
	else inc(node << 1, pos, key);
	tree[node].key = tree[node << 1].key + tree[node << 1 | 1].key;
}
 
void dec(int node, int pos, int key) {
 
	if (tree[node].l == tree[node].r) {
		tree[node].key -= key;
		return;
	}
	int mid = (tree[node].l + tree[node].r) >> 1;
	if (pos > mid) dec(node << 1 | 1, pos, key);
	else dec(node << 1, pos, key);
	tree[node].key = tree[node << 1].key + tree[node << 1 | 1].key;
}
 
int query(int node, int l, int r) {
 
	if (tree[node].l == l && tree[node].r == r) return tree[node].key;
	int mid = (tree[node].l + tree[node].r) >> 1;
	if (l > mid) return query(node << 1 | 1, l, r);
	else if (r <= mid) return query(node << 1, l, r);
	else return query(node << 1, l, mid) + query(node << 1 | 1, mid + 1, r);
}
 
int main() {
 
	ios::sync_with_stdio(false);
	int n; cin >> n;
	buildtree(1, 1, n);
	while (true) {
 
		int tmp1, tmp2; char op[10];
		cin >> op;
		if (op[0] == 'e') break;
		cin >> tmp1 >> tmp2;
		switch (op[0]) {
			case 'i':
				inc(1, tmp1, tmp2);
				break;
			case 'd':
				dec(1, tmp1, tmp2);
				break;
			case 'q':
				cout << query(1, tmp1, tmp2) << endl;
				break;
		}
	}
	return 0;
}