#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 200010;
int k, n;
int a[MAX_N];
 
int main() {
 
	ios::sync_with_stdio(false);
	cin >> k;
	while (k--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + 1 + n);
		for (int i = 1; i < n; ++i) cout << a[i] << " ";
		cout << a[n] << endl;
	}
	return 0;
}