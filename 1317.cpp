#include <iostream>
#include <algorithm>
 
using namespace std;
 
int cmp(int a, int b) {
	return a > b;
}
 
int main() {
 
	int stalls[201];
	int intervals[201];
	int M, S, C;
	cin >> M >> S >> C;
	int minn = 9999999;
	int maxn = 0;
	for (int i = 1; i <= C; i++) {
		cin >> stalls[i];
		maxn = max(maxn, stalls[i]);
		minn = min(minn, stalls[i]);
	}
	sort(stalls + 1, stalls + C + 1);
	for (int i = 1; i <= C; i++) intervals[i] = stalls[i + 1] - stalls[i];
	sort(intervals + 1, intervals + C, cmp);
 
	int result = 0;
	for (int i = 1; i <= M - 1; i++) result += intervals[i];
	int ans = maxn - minn - result + M;
	if (M >= C) ans = C;
	cout << ans << endl;
	return 0;
}