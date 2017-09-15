#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
 
	ios::sync_with_stdio(false);
	int const MAX_N = 5010;
	int n;
	cin >> n;
	int a[MAX_N], b[MAX_N];
	for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
 
	sort(a, a + n);
	sort(b, b + n);
 
	int last = b[0] - a[0], part = 0;
	for (int i = 1; i<n; ++i) {
		if (a[i] <= b[i - 1]) {
			a[i] = a[i - 1];
			last = max(last, b[i] - a[i]);
		}
		else part = max(part, a[i] - b[i - 1]);
	}
	cout << last << " " << part << endl;
	return 0;
}