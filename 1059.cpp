#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
	int num[2001];
	int n;
	long long total = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> num[i];
	sort(num + 1, num + n + 1);
	for (int i = 1; i < n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			int temp = (long long) num[i] * num[j] % 100000000, l = 1, r = n, mid;
			while (r > l) {
				mid = (l + r + 1) / 2;
				if (num[mid] > temp) r = mid - 1;
				else l = mid;
			}
			if ((temp == num[l]) && (l != i) && (l != j)) ++total;
		}
	cout << total * 2 << endl;
	return 0;
}