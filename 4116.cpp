#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 100010;
int pos[MAX_N];
int n, s;

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; ++i) scanf("%d", &pos[i]);
	sort(pos, pos + n);
	int l = 1, r = 1000000000;
	while (l < r - 3) {
		int mid = (l + r) >> 1, cnt = 1, p = 0, flag = 0;
		for (int i = 1; i < n; ++i)
			if (pos[i] - pos[p] >= mid) {
				++cnt; p = i;
				if (cnt >= s) {
					flag = 1; break;
				}
			}
		if (flag) l = mid;
		else r = mid - 1;
	}
	int k;
	for (k = r; k >= l; --k) {
		int cnt = 1, p = 0;
		for (int i = 1; i < n; ++i)
			if (pos[i] - pos[p] >= k) {
				++cnt; p = i;
			}
		if (cnt >= s) break;
	}
	printf("%d\n", k);
	return 0;
}
