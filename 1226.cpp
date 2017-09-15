#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
 
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[100000];
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n - 1; ++i) cout << a[i] << " ";
	cout << a[n - 1];
	return 0;
}