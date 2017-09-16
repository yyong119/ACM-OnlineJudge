#include <cstdio>
#include <cstring>
#define MAX_N 1000000
using namespace std;
 
int a[MAX_N + 1], m[MAX_N + 1];
 
int bs(int maxlen, int tmp) {
 
	int l = 1, r = maxlen;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (m[mid] == tmp) return mid;
		if (m[mid] > tmp) l = mid + 1;
		else r = mid - 1;
	}
	return l;
 
}
 
int bs2(int maxlen, int tmp) {
 
	int l = 1, r = maxlen;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (m[mid] == tmp) return mid;
		if (m[mid] < tmp) l = mid + 1;
		else r = mid - 1;
	}
	return l;
 
}
 
int main() {
 
	int n, maxlen, num = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
 
	maxlen = 1; m[maxlen] = a[1];
	for (int i = 2; i <= n; ++i)
		if (a[i] <= m[maxlen]) {
			m[++maxlen] = a[i];
		}
		else {
			int p = bs(maxlen, a[i]);
			m[p] = a[i];
		}
	printf("%d\n", maxlen);
 
	memset(m, 0, sizeof(m));
	maxlen = 1; m[maxlen] = a[1];
	for (int i = 2; i <= n; ++i)
		if (a[i] > m[maxlen]) {
			m[++maxlen] = a[i];
		}
		else {
			int p = bs2(maxlen, a[i]);
			m[p] = a[i];
		}
	printf("%d\n", maxlen);
	return 0;
}