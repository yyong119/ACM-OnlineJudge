#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAX_P = 10001;
struct node {
	int l, r, key;
}tree[MAX_P << 2];
 
void buildtree(int t, int l, int r) {
 
	if (l == r) {
		tree[t].l = tree[t].r = l;
		return;
	}
	int mid = (l + r) >> 1;
	buildtree(t << 1, l, mid);
	buildtree(t << 1 | 1, mid + 1, r);
	tree[t].l = l; tree[t].r = r;
}
 
void update(int t, int point) {
 
	tree[t].key++;
	if (tree[t].l == tree[t].r) return;
	int mid = (tree[t].l + tree[t].r) >> 1;
	if (point <= mid) update(t << 1, point);
	else update(t << 1 | 1, point);
}
 
int query(int t, int l, int r) {
 
	if (tree[t].l == l && tree[t].r == r) return tree[t].key;
	int mid = (tree[t].l + tree[t].r) >> 1;
	if (r <= mid) return query(t << 1, l, r);
	else if (l > mid) return query(t << 1 | 1, l, r);
	else return query(t << 1, l, mid) + query(t << 1 | 1, mid + 1, r);
}
 
int main() {
 
	int n, m;
	scanf("%d%d", &n, &m);
	buildtree(1, 1, MAX_P);
	for (int i = 0; i < n; ++i) {
		int tmp;
		scanf("%d", &tmp);
		update(1, tmp);
	}
	for (int i = 0; i < m; ++i) {
		int tmpl, tmpr;
		scanf("%d%d", &tmpl, &tmpr);
		printf("%d\n", query(1, tmpl, tmpr));
	}
	return 0;
}