#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 3000010
using namespace std;
int n, Q, X[N], root[N];
int shu[N], num[N], top, tot;
int B[N];
int tsz, c[5000010][2], Sum[5000010], troot[100010];
int xsz, gs[N], ls[N], rs[N];
 
int find(int x) {
 
	int l = 1, r = tot, mid;
	while (l + 1 < r) {
		mid = (l + r) >> 1;
		if (num[mid] == x) return mid;
		if (num[mid] < x) l = mid;
		else r = mid;
	}
	if (num[l] == x) return l;
	else return r;
}
 
void Insert(int &x, int y, int l, int r, int p) {
 
	x = ++xsz;
	gs[x] = gs[y] + 1;
	ls[x] = ls[y]; rs[x] = rs[y];
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (p <= mid) Insert(ls[x], ls[y], l, mid, p);
	else Insert(rs[x], rs[y], mid + 1, r, p);
}
 
int Querysecond(int a, int b) {
 
	int L = root[a - 1], R = root[b];
	int l = 1, r = tot, mid, k = 2;
	while (l != r) {
		mid = (l + r) >> 1;
		if (gs[rs[R]] - gs[rs[L]] >= k) {
			l = mid + 1; L = rs[L]; R = rs[R];
		}
		else {
			k -= gs[rs[R]] - gs[rs[L]];
			r = mid; L = ls[L]; R = ls[R];
		}
	}
	return num[l];
}
 
void Trie_add(int x, int W) {
 
	int p = troot[W - 1], now = ++tsz;
	troot[W] = now;
	for (int i = (1 << 30); i > 0; i >>= 1) {
		Sum[now] = Sum[p] + 1;
		c[now][0] = c[p][0]; c[now][1] = c[p][1];
		if (x & i) {
			p = c[p][1];
			c[now][1] = ++tsz;
			now = c[now][1];
		}
		else {
			p = c[p][0];
			c[now][0] = ++tsz;
			now = c[now][0];
		}
	}
	Sum[now] = Sum[p] + 1;
}
 
int Trie_query(int x, int L, int R) {
 
	int res = 0, l = troot[L - 1], r = troot[R];
	for (int i = (1 << 30); i > 0; i >>= 1) {
		int p;
		if (x & i) p = 0; else p = 1;
		if (Sum[c[r][p]] - Sum[c[l][p]] > 0) {
			res += i;
			l = c[l][p]; r = c[r][p];
		}
		else {
			l = c[l][p ^ 1]; r = c[r][p ^ 1];
		}
	}
	return res;
}
 
int main() {
 
	int l, r;
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &X[i]);
		shu[++top] = X[i];
	}
	sort(shu + 1, shu + 1 + top);
	num[++tot] = shu[1];
	for (int i = 2; i <= top; i++) if (shu[i] != shu[i - 1]) num[++tot] = shu[i];
	for (int i = 1; i <= n; i++) X[i] = find(X[i]);
	for (int i = 1; i <= n; i++) {
		Insert(root[i], root[i - 1], 1, tot, X[i]);
		Trie_add(num[X[i]], i);
	}
	for (int i = 1; i <= Q; i++) {
		scanf("%d %d", &l, &r);
		int x = Querysecond(l, r);
		printf("%d\n", Trie_query(x, l, r));
	}
	return 0;
}