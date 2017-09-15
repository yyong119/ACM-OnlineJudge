#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 100010;
int n, m, i;
int a[MAXN];
 
int main() {
 
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	while (m--) {
		int tmp, l = 1, r = n, mid;
		scanf("%d", &tmp);
		while (l < r) {
			mid = (l + r) >> 1;
			if (tmp < a[mid]) r = mid - 1;
			else l = mid + 1;
		}
		for (i = mid - 2; i <= mid + 2; ++i)
			if (tmp < a[i]) break;
		if (n - i + 1 >= 0) printf("%d\n", n - i + 1);
		else printf("%d\n", 0);
	}
	return 0;
}