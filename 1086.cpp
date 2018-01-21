#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 105;
const int MAXM = 15;
const int MAXS = 65;

char matrix[MAXN][MAXM];
int f[MAXN][MAXS][MAXS], vst[MAXS], num[MAXS], originState[MAXN];

int main() {

	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		originState[i] = 0;
		scanf("%s", &matrix[i]);
		for (int j = 0; j < m; ++j)
			if (matrix[i][j] == 'P')
				originState[i] += 1 << (m - j - 1);
	}

	memset(f, sizeof(f), 0);
	int vnum = 0;
	for (int i = 0; i < (1 << m); ++i)
		if (!(i & (i << 1)) && !(i & (i << 2))) {
			vst[vnum] = i;
			int tmp = 0, r = i;
			for (; r; r &= r - 1, ++tmp);
			num[vnum++] = tmp;
		}

	for (int i = 0; i < vnum; ++i)
		if (!(vst[i] & (~originState[0])))
			f[0][i][0] = num[i];

	for (int i = 1; i < n; ++i)
		for (int j = 0; j < vnum; ++j) { //第i行
			if ((~originState[i]) & vst[j]) continue;
			for (int k = 0; k < vnum; ++k) { //第i - 1行
				if ((~originState[i - 1]) & vst[k]) continue;
				if (vst[j] & vst[k]) continue;
				for (int t = 0; t < vnum; ++t) { //第i - 2行
					if (vst[j] & vst[t]) continue;
					if (f[i - 1][k][t] == -1) continue;
					f[i][j][k] = max(f[i][j][k], f[i - 1][k][t] + num[j]);
				}
			}
		}

	int ret = 0;
	for (int i = 0; i < vnum; ++i)
		for (int j = 0; j < vnum; ++j)
			ret = max(f[n - 1][i][j], ret);
	printf("%d\n", ret);
	return 0;
}
