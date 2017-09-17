#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[10001], b[10001];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	long num = 0;
	for (int i = 1; i <= n; ++i) num += abs(a[i] - b[n + 1 - i]);
	cout << num << endl;
	return 0;
}