#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 1005;
char a[MAX_N], b[MAX_N];
int n, m;
int f[MAX_N][MAX_N];
 
int main() {
 
	cin >> n >> m;
	cin >> a; cin >> b;
	for (int i = n; i > 0; --i) a[i] = a[i - 1];
	for (int i = m; i > 0; --i) b[i] = b[i - 1];
	a[0] = b[0] = '*';
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
	cout << f[n][m] << endl;
	return 0;
}