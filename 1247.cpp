#include <iostream>
#define MAX_N 10000
using namespace std;

int tree[MAX_N << 2];
int n, m;

void update(int d, int dl, int dr, int l, int r) {
	if (dl == dr) tree[d] = 1;
	else {
		int mid = (dl + dr) >> 1;
		if (r <= mid) update(d << 1, dl, mid, l, r);
		else if (l > mid) update(d << 1 | 1, mid + 1, dr, l, r);
		else {
			update(d << 1, dl, mid, l, mid);
			update(d << 1 | 1, mid + 1, dr, mid + 1, r);
		}
		tree[d] = tree[d << 1] + tree[d << 1 | 1];
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin >> n >> m;
	while(m--) {
		int l, r;
		cin >> l >> r;
		update(1, 1, n + 1, l + 1, r + 1);
	}
	cout << n + 1 - tree[1] << endl;
	return 0;
}
