#include <iostream>
using namespace std;

int path[35][35], p;
int dp[35][35], a[35];

int dfs(int l, int r) {

	if (dp[l][r] > 0) return dp[l][r];
	if (l > r) return 1;
	if (l == r) {
		dp[l][r] = a[l];
		path[l][r] = l;
	}
	else
	for (int i = l; i <= r; ++i) {
		int x = dfs(l, i - 1) * dfs(i + 1, r) + a[i];
		if (x > dp[l][r]) {
			dp[l][r] = x;
			path[l][r] = i;
		}
	}
	return dp[l][r];
}

void print (int l, int r) {

	if (l > r) return;
	if (p++) cout << " " << path[l][r];
	else cout << path[l][r];
	print(l, path[l][r] - 1);
	print(path[l][r] + 1, r);
}

int main() {

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cout << dfs(1, n) << endl;
	p = 0;
	print(1, n);
	return 0;
}
