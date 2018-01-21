#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int INF = 100000007;

int a[201110], f[201110];
int n, t;
struct node {
	int l, r, num;
}tree[1000005];

void buildtree(int index, int l, int r) {

	if (l == r) {
		tree[index].l = l; tree[index].r = r;
		tree[index].num = INF;
	}
	else {
		int mid = (l + r) >> 1;
		buildtree(index << 1, l, mid);
		buildtree(index << 1 | 1, mid + 1, r);
		tree[index].l = l; tree[index].r = r; tree[index].num = INF;
	}
}

void addElement(int index, int pos, int num) {
	if (tree[index].l == pos && tree[index].r == pos) tree[index].num = num;
	else {
		int mid = (tree[index].l + tree[index].r) >> 1;
		if (pos <= mid) addElement(index << 1, pos, num);
		else addElement(index << 1 | 1, pos, num);
		tree[index].num = min(tree[index << 1].num, tree[index << 1 | 1].num);
	}
}

int querymin(int index, int l, int r) {

	if (tree[index].l == l && tree[index].r == r) return tree[index].num;
	int mid = (tree[index].l + tree[index].r) >> 1;
	if (r <= mid) return querymin(index << 1, l, r);
	else if (l > mid) return querymin(index << 1 | 1, l, r);
	else return min(querymin(index << 1, l, mid), querymin(index << 1 | 1, mid + 1, r));
}

bool checkOK(int maxInterval) {

	memset(f, sizeof(f), 0);
	for (int i = 1; i <= maxInterval + 1; ++i) {
		f[i] = a[i];
		addElement(1, i, f[i]);
	}
	for (int i = maxInterval + 2; i <= n; ++i) {
		f[i] = a[i] + querymin(1, i - maxInterval - 1, i - 1);
		addElement(1, i, f[i]);
	}
	for (int i = n - maxInterval; i <= n; ++i)
		if (f[i] <= t) return true;
	return false;
}

int main() {

	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	buildtree(1, 1, n);
	int l = 1, r = n - 2, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (checkOK(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", r);
	return 0;
}
