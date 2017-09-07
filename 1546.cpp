#include <cstdio>
#include <iostream>
using namespace std;
inline const int getint() {
	int r = 0, k = 1;
	char c = getchar();
	for (; c<'0' || c>'9'; c = getchar()) if (c == ' - ') k = -1;
	for (; c >= '0'&&c <= '9'; c = getchar()) r = r * 10 + c - '0';
	return k*r;
}
 
const int N = 100010;
int n, MD;
 
struct node {
	int sum, add, mul;
	void upd(int a, int m, int len) {
		add = ((long long)add*m + a) % MD;
		mul = ((long long)mul*m) % MD;
		sum = ((long long)sum*m + (long long)a*len) % MD;
	}
}t[N << 2];
 
void pushdown(int x, int len) {
	if (t[x].add != 0 || t[x].mul != 1)
		t[x << 1].upd(t[x].add, t[x].mul, (len - (len >> 1))),
		t[x << 1 | 1].upd(t[x].add, t[x].mul, len >> 1),
		t[x].add = 0, t[x].mul = 1;
}
 
void pushup(int x) {
	t[x].sum = (t[x << 1].sum + t[x << 1 | 1].sum) % MD; 
}
void build(int l, int r, int x) {
	t[x].add = 0;
	t[x].mul = 1;
	if (l == r) { t[x].sum = getint(); return; }
	int mid = (l + r) >> 1;
	build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
	pushup(x);
}
 
void update(int l, int r, int x, int L, int R, int add, int mul) {
	if (L <= l && r <= R) { t[x].upd(add, mul, r - l + 1); return; }
	pushdown(x, r - l + 1);
	int mid = (l + r) >> 1;
	if (L <= mid) update(l, mid, x << 1, L, R, add, mul);
	if (mid<R) update(mid + 1, r, x << 1 | 1, L, R, add, mul);
	pushup(x);
}
 
int query(int l, int r, int x, int L, int R) {
	if (L <= l && r <= R) return t[x].sum;
	pushdown(x, r - l + 1);
	int mid = (l + r) >> 1, ret = 0;
	if (L <= mid) ret += query(l, mid, x << 1, L, R);
	if (mid<R) ret += query(mid + 1, r, x << 1 | 1, L, R);
	ret %= MD;
	return ret;
}
 
int main() {
	scanf("%d%d", &n, &MD);
	build(1, n, 1);
	int m;
	scanf("%d", &m);
	while (m--) {
		int c;
		scanf("%d", &c);
		int l, r, x;
		switch (c) {
			case 1:
				scanf("%d%d%d", &l, &r, &x);
				update(1, n, 1, l, r, 0, x);
				break;
			case 2:
				scanf("%d%d%d", &l, &r, &x);
				update(1, n, 1, l, r, x, 1);
				break;
			case 3:
				scanf("%d%d", &l, &r);
				printf("%d\n", query(1, n, 1, l, r));
				break;
		}
	}
	return 0;
}