#include <iostream>
using namespace std;
const int MAX_N = 100010;
long long ans;
int n;
int a[MAX_N];
 
void merge(int l, int r) {
 
	int mid = (l + r) >> 1, i = l, j = mid + 1, k = l;
	int tmp[MAX_N];
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) tmp[k++] = a[i++];
		else {
			ans += mid - i + 1;
			tmp[k++] = a[j++];
		}
	}
	while (i <= mid) tmp[k++] = a[i++];
	while (j <= r) tmp[k++] = a[j++];
	for (int i = l; i <= r; ++i) a[i] = tmp[i];
}
 
void mergesort(int l, int r) {
 
	if (l == r) return;
	int mid = (l + r) >> 1;
	mergesort(l, mid);
	mergesort(mid + 1, r);
	merge(l, r);
}
 
int main() {
 
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	mergesort(1, n);
	cout << ans << endl;
	return 0;
}