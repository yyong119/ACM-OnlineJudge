#include <iostream>
using namespace std;
 
int N, X, Y;
 
struct node {
	int left, right, parent;
	node() :left(0), right(0), parent(0) {}
};
 
node *tree;
 
class disjointSet {
private:
	int *parent;
 
public:
	disjointSet(int n) {
		parent = new int[n + 1];
		for (int i = 0; i < n; ++i)parent[i + 1] = -1;
		parent[0] = 0;
	}
	~disjointSet() {
		delete[]parent;
	}
	int find(int x) {
		if (parent[x]<0)return x;
		return parent[x] = find(parent[x]);
	}
	void merge(int root1, int root2) {
		if (tree[root1].parent == root2) {
			parent[root2] += parent[root1];
			parent[root1] = root2;
		}
		else {
			parent[root1] += parent[root2];
			parent[root2] = root1;
		}
	}
};
 
int LCA(disjointSet& d, node *t, int root) {
	if (!root)return -1;
	int tmp;
	if ((tmp = LCA(d, t, t[root].left)) > 0)return tmp;
	else if ((tmp = LCA(d, t, t[root].right) > 0))return tmp;
	else {
		if (t[root].left)d.merge(root, t[root].left);
		if (t[root].right)d.merge(root, t[root].right);
		if ((tmp = d.find(X)) == d.find(Y))return tmp;
		else return -1;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> X >> Y;
	tree = new node[N + 1];
	for (int i = 1; i <= N; ++i) {
		cin >> tree[i].left >> tree[i].right;
		tree[tree[i].left].parent = tree[tree[i].right].parent = i;
	}
	int root = 1;
	while (tree[root].parent)root = tree[root].parent;
	disjointSet d(N);
	cout << LCA(d, tree, root) << endl;
	delete[]tree;
	return 0;
}
