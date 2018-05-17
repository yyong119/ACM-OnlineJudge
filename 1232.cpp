#include <iostream>
using namespace std;
 
int N,A, B, P, Q, x, y;
bool *mark, **Path;
int *path, pos;
 
int bSearch(int P) {
	int l = 1, r = N;
	while (l <= r) {
		int mid = l + r >> 1;
		if ((mid * (mid + 1) >> 1) < P)l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
 
inline int getPosition(int x, int y) {
	return ((x * (x - 1) >> 1) + y);
}
 
class disjointSet {
private:
	int *parent;
 
public:
	disjointSet(int n) : parent(new int[n + 1]) {
		for (int i = 1; i <= n; ++i) parent[i] = -1;
	}
	~disjointSet() {
		delete [] parent;
	}
	int find(int x) {
		if (parent[x] < 0) return x;
		else {
			int tmp = parent[x];
			while (parent[tmp] > 0)tmp = parent[tmp];
			int y;
			while (x != tmp) {
				y = parent[x];
				parent[x] = tmp;
				x = y;
			}
			return tmp;
		}
	}
	void Union(int root1, int root2) {
 
		if (root1 == root2)return;
		if (parent[root1] < parent[root2]) {
			parent[root1] += parent[root2];
			parent[root2] = root1;
		}
		else {
			parent[root2] += parent[root1];
			parent[root1] = root2;
		}
	}
};
 
bool dfs(int x, int y) {
 
	mark[getPosition(x, y)] = true;
	if (getPosition(x, y) == B) return true;
	if (Path[0][getPosition(x, y)] && !mark[getPosition(x - 1, y - 1)]) {
		if (dfs(x - 1, y - 1)) {
			path[pos++] = getPosition(x - 1, y - 1);
			return true;
		}
	}
	if (Path[1][getPosition(x, y)] && !mark[getPosition(x - 1, y)]) {
		if (dfs(x - 1, y)) {
			path[pos++] = getPosition(x - 1, y);
			return true;
		}
	}
	if (Path[2][getPosition(x, y)] && !mark[getPosition(x + 1, y)]) {
		if (dfs(x + 1, y)) {
			path[pos++] = getPosition(x + 1, y);
			return true;
		}
	}
	if (Path[3][getPosition(x, y)] && !mark[getPosition(x + 1, y + 1)]) {
		if (dfs(x + 1, y + 1)) {
			path[pos++] = getPosition(x + 1, y + 1);
			return true;
		}
	}
	return false;
}
 
void deleteData() {
	for (int i = 0; i < 4; ++i) delete[] Path[i];
	delete[] Path; delete[] mark; delete[] path;
}
 
int main() {
 
	ios::sync_with_stdio(false);
	cin >> N >> A >> B;
	Path = new bool* [4];
	for (int i = 0; i < 4; ++i)
		Path[i] = new bool[(N * (N + 1) >> 1) + 1]();
	disjointSet dJS(N * (N + 1) >> 1);
	while (cin >> P >> Q) {
		x = bSearch(P);
		y = P - (x * (x - 1) >> 1);
		switch (Q) {
		case 0:
			if (y != 1) {
				dJS.Union(dJS.find(P), dJS.find(P - x));
				Path[0][P] = Path[3][P - x] = true;
			}
			break;
		case 1:
			if (y != x) {
				dJS.Union(dJS.find(P), dJS.find(P - x + 1));
				Path[1][P] = Path[2][P - x + 1] = true;
			}
			break;
		case 2:
			if (x != N) {
				dJS.Union(dJS.find(P), dJS.find(P + x));
				Path[2][P] = Path[1][P + x] = true;
			}
			break;
		case 3:
			if (x != N) {
				dJS.Union(dJS.find(P), dJS.find(P + x + 1));
				Path[3][P] = Path[0][P + x + 1] = true;
			}
		}
		if (dJS.find(A) == dJS.find(B)) break;
	}
	x = bSearch(A);
	y = A - (x * (x - 1) >> 1);
	mark = new bool[(N * (N + 1) >> 1) + 1]();
	path = new int[(N * (N + 1) >> 1)]();
	if (dfs(x, y)) path[pos++] = A;
	for (int i = pos - 1; i > 0; --i) cout << path[i] << ' ';
	cout << path[0] << endl;
	deleteData();
	return 0;
}
