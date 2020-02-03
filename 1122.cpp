#include <iostream>
#include <cstdio>
#define MAX_N 50010
using namespace std;

struct Node {
	int l_con, r_con, c_con;
} tree[MAX_N << 3];
int tag[MAX_N << 3];
int n, m;

inline int read() {
	char c = getchar(); int res = 0, flag = 1;
	while(c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') {
		flag = -1, c = getchar();
	}
	while(c >= '0' && c <= '9')
		res = 10 * res + c - '0', c = getchar();
	return res * flag;
}

void create_tree(int x, int l, int r) {
	tree[x].l_con = r - l + 1;
	tree[x].r_con = tree[x].l_con;
	tree[x].c_con = tree[x].l_con;
	if (r == l) return;
	int mid = (l + r) >> 1;
	create_tree(x << 1, l, mid);
	create_tree(x << 1 | 1, mid + 1, r);

}

void push_down(int x, int l, int r) {
	if (tag[x] == 1) {// order
		tree[x].l_con = 0;
		tree[x].r_con = 0;
		tree[x].c_con = 0;
	}
	else {// free
		tree[x].l_con = r - l + 1;
		tree[x].r_con = tree[x].l_con;
		tree[x].c_con = tree[x].l_con;
	}
	tag[x << 1] = tag[x];
	tag[x << 1 | 1] = tag[x];
	tag[x] = 0;
}

void push_up(int x, int l, int r) {
	tree[x].l_con = tree[x << 1].l_con;
	tree[x].r_con = tree[x << 1 | 1].r_con;
	int mid = (l + r) >> 1;
	if (tree[x << 1].l_con == mid - l + 1)
		tree[x].l_con += tree[x << 1 | 1].l_con;
	if (tree[x << 1 | 1].r_con == r - mid)
		tree[x].r_con += tree[x << 1].r_con;
	tree[x].c_con = max(tree[x << 1].r_con + tree[x << 1 | 1].l_con, max(tree[x << 1].c_con, tree[x << 1 | 1].c_con));
}

int find_min(int x, int l, int r, int length) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (tag[x << 1]) push_down(x << 1, l, mid);
	if (tag[x << 1 | 1]) push_down(x << 1 | 1, mid + 1, r);

	if (tree[x << 1].c_con >= length)
		return find_min(x << 1, l, mid, length);
	else if (tree[x << 1].r_con + tree[x << 1 | 1].l_con >= length)
		return mid - tree[x << 1].r_con + 1;
	else return find_min(x << 1 | 1, mid + 1, r, length);
}

void order(int x, int l, int r, int tar_l, int tar_r) {
	if (l == tar_l && r == tar_r) {
		tree[x].l_con = 0;
		tree[x].r_con = 0;
		tree[x].c_con = 0;
		if (r != l) {
			tag[x << 1] = 1;
			tag[x << 1 | 1] = 1;
		}
		return;
	}
	int mid = (l + r) >> 1;
	if (tag[x << 1]) push_down(x << 1, l, mid);
	if (tag[x << 1 | 1]) push_down(x << 1 | 1, mid + 1, r);
	if (tar_r <= mid) order(x << 1, l, mid, tar_l, tar_r);
	else if (tar_l > mid) order(x << 1 | 1, mid + 1, r, tar_l, tar_r);
	else {
		order(x << 1, l, mid, tar_l, mid);
		order(x << 1 | 1, mid + 1, r, mid + 1, tar_r);
	}
	push_up(x, l, r);
}

void free(int x, int l, int r, int tar_l, int tar_r) {
	if (l == tar_l && r == tar_r) {
		tree[x].l_con = r - l + 1;
		tree[x].r_con = tree[x].l_con;
		tree[x].c_con = tree[x].l_con;
		if (r != l) {
			tag[x << 1] = -1;
			tag[x << 1 | 1] = -1;
		}
		return;
	}
	
	int mid = (l + r) >> 1;
	if (tag[x << 1]) push_down(x << 1, l, mid);
	if (tag[x << 1 | 1]) push_down(x << 1 | 1, mid + 1, r);
	if (tar_r <= mid) free(x << 1, l, mid, tar_l, tar_r);
	else if (tar_l > mid) free(x << 1 | 1, mid + 1, r, tar_l, tar_r);
	else {
		free(x << 1, l, mid, tar_l, mid);
		free(x << 1 | 1, mid + 1, r, mid + 1, tar_r);
	}
	push_up(x, l, r);
}

int main() {
	n = read(); m = read();
	create_tree(1, 1, n);
	while (m--) {
		int op; op = read();
		if (op == 1) {
			int L; L = read();
			if (L <= tree[1].c_con) {
				int x = find_min(1, 1, n, L);
				printf("%d\n", x);
				order(1, 1, n, x, x + L - 1);
			}
			else printf("0\n");
		}
		else {
			int x, y; x = read(); y = read();
			free(1, 1, n, x, x + y - 1);
		}
	}
	return 0;
}
