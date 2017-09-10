#include <iostream>
#include <cstring>
using namespace std;
 
const int MAX_N = 50010;
 
int main() {
 
	ios::sync_with_stdio(false);
	int l, n, m;
	cin >> l >> n >> m;
	int a[MAX_N]; a[0] = 0; a[n + 1] = l;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int L = 1, R = l, mid, remove;
	while (L < R) {
		int b[MAX_N];
		memcpy(b, a, sizeof(a));
		mid = (L + R) >> 1; remove = 0;
		for (int i = 1; i <= n + 1; ++i)
			if (b[i] - b[i - 1] < mid) {
				b[i] = b[i - 1];
				if (++remove > m) break;
			}
		if (remove <= m) L = mid + 1; else R = mid - 1;
	}
	int k;
	for (k = mid + 1; k >= mid - 1; --k) {
		int remove = 0;
		int b[MAX_N];
		memcpy(b, a, sizeof(a));
		for (int i = 1; i <= n + 1; ++i)
			if (b[i] - b[i - 1] < k) {
				b[i] = b[i - 1];
				if (++remove > m) break;
			}
		if (remove <= m) break;
	}
	cout << k << endl;
	return 0;
}