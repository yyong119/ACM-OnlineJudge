#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int map[1250][1250], cnt[1250][1250];
int maxS = 0;

int main() {

	ios::sync_with_stdio(false);
	int w, l;
	cin >> w >> l;
	char tmp;
	for (int i = 1; i <= w; ++i)
		for (int j = 1; j <= l; ++j) {
			cin >> tmp;
			if (tmp == 'X') map[i][j] = 1;
			cnt[i][j] = map[i][j] + cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
		}
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < l; ++j) {
			if (map[i + 1][j + 1]) continue;
			int xr = w - i, yr = l - j;
			if (xr <= maxS || (yr >> 1) <= maxS) continue;
			// //横向		//又踩坑了，这个要用二分，二分，二分!!!
			// int Hmax = min(yr / 2, xr);
			// for (int p = Hmax; p > maxS; --p)
			// 	if (cnt[i][j + p * 2] + cnt[i + p][j] - cnt[i][j] == cnt[i + p][j + 2 * p]) {
			// 		maxS = p;
			// 		break;
			// 	}
			int r = min(yr / 2, xr), l = 1, mid;
			while (l < r) {
				mid = (l + r + 1) / 2;
				if (cnt[i][j + mid * 2] + cnt[i + mid][j] - cnt[i][j] == cnt[i + mid][j + 2 * mid])
					l = mid;
				else r = mid - 1;
				// cout << l << mid << r << endl;
			}
			if (cnt[i][j + mid * 2] + cnt[i + mid][j] - cnt[i][j] != cnt[i + mid][j + 2 * mid]) mid--;
			if (mid > maxS) maxS = mid;
			//纵向			//哎哟，注意看题目啊，不能纵向的≧ ﹏ ≦
			// int Vmax = min(yr, xr / 2);
			// for (int p = Vmax; p > maxS; --p)
			// 	if (cnt[i][j + p] + cnt[i + 2 * p][j] - cnt[i][j] == cnt[i + 2 * p][j + p]) {
			// 		maxS = p;
			// 		break;
			// 	}
		}
	}
	cout << maxS * maxS * 2 << endl;
	return 0;
}
