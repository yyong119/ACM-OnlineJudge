#include <iostream>
#define MAX_N 100010
using namespace std;

int n;
int connect[MAX_N][210], length[MAX_N], seg[MAX_N][210];
bool caled[MAX_N];


int getComponent(int s, int x) {
	int len = length[x];
	int res = 1;    
	if (caled[x]) {
		for (int i = 0; i < len; ++i) if (connect[x][i] != s)
			res += seg[x][i];
	}
	else { 
		int tmp = 0;
		for (int i = 0; i < len - 1; ++i) {
			seg[x][i] = getComponent(x, connect[x][i]);
			tmp += seg[x][i];
			if (connect[x][i] != s)
				res += seg[x][i];
		}
		seg[x][len - 1] = n - 1 - tmp;
		caled[x] = true;
	}
	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		connect[x][length[x]++] = y;
		connect[y][length[y]++] = x;
	}
	for (int i = 1; i <= n; ++i)
		if (length[i] == 1) {
			seg[i][0] = n - 1;
			caled[i] = true;
		}
	for (int i = 1; i <= n; ++i)
		if (length[i] == 2) {
			if (length[connect[i][0]] == 1) {
				seg[i][0] = 1; seg[i][1] = n - 2;
				caled[i] = true;
			}
			if (length[connect[i][1]] == 1) {
				seg[i][1] = 1; seg[i][0] = n - 2;
				caled[i] = true;
			}
		}

	for (int i = 1; i <= n; ++i)
		if (!caled[i]) {
			int len = length[i], tmp = 0;
			for (int j = 0; j < len - 1; ++j) {
				seg[i][j] = getComponent(i, connect[i][j]);
				tmp += seg[i][j];
			}
			seg[i][len - 1] = n - 1 - tmp;
			caled[i] = true;
		}

	for (int i = 1; i <= n; ++i) {
		bool flag = true;
		for (int j = 0; j < 3; ++j)
			if (seg[i][j] > n >> 1) {
				flag = false;
				break;
			}
		if (flag) cout << i << endl;
	}
	return 0;
}
