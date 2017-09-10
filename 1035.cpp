#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N = 20010;
struct node {
	int id, num;
};
 
inline bool cmp(node x, node y) {
	if (x.num == y.num) return x.id < y.id;
	else return x.num > y.num;
}
 
int main() {
 
	ios::sync_with_stdio(false);
	int n; cin >> n;
	node a[MAX_N], b[MAX_N];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].num;
		a[i].id = i;
	}
	int k; cin >> k;
	while (k--) {
		char op[5];
		cin >> op;
		if (op[0] == 'Q') {
			int r, temp; cin >> r;
			memcpy(b, a, sizeof(a));
			sort(b + 1, b + n + 1, cmp);
			while (r--) {
				cin >> temp;
				cout << b[temp].id << " ";
			}
			cout << endl;
		}
		else {
				int p, m;
				cin >> p >> m;
				a[p].num = m;
		}
	}
	return 0;
}