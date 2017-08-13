#include <iostream>
#include <queue>
 
using namespace std;
struct treedata {
	int l, r, pre, value;
} tree[100001];
int n, i, now, root;
queue<int> que;
 
int main() {
 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tree[i].l >> tree[i].r >> tree[i].value;
		tree[tree[i].l].pre = i; tree[tree[i].r].pre = i;
	}
	for (root = 1; root <= n; ++root) if (!tree[root].pre) break;
	if (tree[root].l) que.push(tree[root].l);
	if (tree[root].r) que.push(tree[root].r);
	cout << tree[root].value;
	while (!que.empty()) {
		now = que.front();
		que.pop();
		cout << " " << tree[now].value;
		if (tree[now].l) que.push(tree[now].l);
		if (tree[now].r) que.push(tree[now].r);
	}
	return 0;
}