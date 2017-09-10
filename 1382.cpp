#include <iostream>
#include <algorithm>
#define MAX_N 100010
using namespace std;
 
int main() {
 
	ios::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	int a[MAX_N];
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	long long total = 0;
	int back = n - 1;
	for (int i = 0; i < n; ++i) {
		while (a[i] + a[back] > s) --back;
		if (back > i) total += back - i;
			else break;
	}
	cout << total << endl;
	return 0;
}