#include <cstdio>
using namespace std;
const int MAX_N = 100010;
struct node {
	long size, right, left, key;
}tree[MAX_N];
long tt, t, minwage, deltawage;
 
void right_rotate(long& t) {
 
	long tmp = tree[t].left;
	tree[t].left = tree[tmp].right;
	tree[tmp].right = t;
	tree[tmp].size = tree[t].size;
	tree[t].size = tree[tree[t].left].size + tree[tree[t].right].size + 1;
	t = tmp;
}
 
void left_rotate(long& t) {
 
	long tmp = tree[t].right;
	tree[t].right = tree[tmp].left;
	tree[tmp].left = t;
	tree[tmp].size = tree[t].size;
	tree[t].size = tree[tree[t].left].size + tree[tree[t].right].size + 1;
	t = tmp;
}
 
void maintain(long& t, bool flag) {
 
	if (!flag) {
		if (tree[tree[tree[t].left].left].size > tree[tree[t].right].size)
			right_rotate(t);
		else if (tree[tree[tree[t].left].right].size > tree[tree[t].right].size) {
			left_rotate(tree[t].left);
			right_rotate(t);
		}
		else return;
	}
	else {
		if (tree[tree[tree[t].right].right].size > tree[tree[t].left].size)
			left_rotate(t);
		else if (tree[tree[tree[t].right].left].size > tree[tree[t].left].size) {
			right_rotate(tree[t].right);
			left_rotate(t);
		}
		else return;
	}
	maintain(tree[t].left, false);
	maintain(tree[t].right, true);
	maintain(t, true);
	maintain(t, false);
}
 
void insertnum(long& t, long value) {
 
	if (t == 0) {
		t = ++tt;
		tree[t].key = value;
		tree[t].size = 1;
	}
	else {
		++tree[t].size;
		if (value >= tree[t].key) insertnum(tree[t].right, value);
		else insertnum(tree[t].left, value);
		maintain(t, value >= tree[t].key);
	}
}
void deletenum(long& t) {
 
	if (t == 0) return;
	if (tree[t].key + deltawage >= minwage) {
		deletenum(tree[t].left);
		tree[t].size = tree[tree[t].left].size + tree[tree[t].right].size + 1;
	}
	else {
		t = tree[t].right;
		deletenum(t);
	}
}
 
long select(long& t, long k) {
 
	if (tree[tree[t].right].size + 1 == k) return t;
	if (tree[tree[t].right].size + 1 >= k) return select(tree[t].right, k);
	else return select(tree[t].left, k - tree[tree[t].right].size - 1);
}
 
int main() {
 
	int n, tmp;
	char op[10];
	scanf("%d%ld", &n, &minwage);
	while (n--) {
		scanf("%s%d", &op, &tmp);
		switch (op[0]) {
			case 'I':
				if (tmp >= minwage) insertnum(t, tmp - deltawage);
				break;
			case 'A':
				deltawage += tmp;
				break;
			case 'S':
				deltawage -= tmp;
				deletenum(t);
				break;
			case 'F':
				if (tmp > tree[t].size) printf("%d\n", -1);
				else printf("%ld\n", deltawage + tree[select(t, tmp)].key);
				break;
		}
	}
	printf("%ld", tt - tree[t].size);
	return 0;
}