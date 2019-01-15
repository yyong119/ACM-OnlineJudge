#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 100010;
 
int main() {
 
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int a[MAX_N], b[MAX_N];
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	long long maxx = 0, minx = 0;
	for (int i = 0; i < n; ++i) {
		maxx += (long long) a[i] * b[i];
		minx += (long long) a[i] * b[n - i - 1];
	}
	cout << maxx << " " << minx << endl;
	return 0;
}