#include <iostream>
#include <cstring>
using namespace std;
 
int W, H;
long long cnt = 1;
long long dp[12][1 << 12];
 
void findall(int line, int state, int pos) {
 
	if (pos == W) {
		dp[line][state] += cnt;
		return;
	}
	findall(line, state, pos + 1);//Leave this position empty
	if (pos <= W - 2 && !(state & (1 << pos)) && !(state & (1 << (pos + 1)))) {//Fill two horizontal positions
		int next = state | (1 << pos) | (1 << (pos + 1));
		findall(line, next, pos + 2);
	}
}
 
int main() {
 
	while (cin >> W >> H && W != 0) {
 
		if (W > H) { int tmp = W; W = H; H = tmp; }
		if (W * H % 2 == 1) {
			cout << 0 << endl; continue;
		}
		memset(dp, 0, sizeof(dp));
		cnt = 1;
 
		findall(1, 0, 0);
		for (int i = 2; i <= H; ++i)
			for (int j = 0; j < (1 << W); ++j) {
				if (dp[i - 1][j]) cnt = dp[i - 1][j];
					else continue;
				findall(i, (~j) & ((1 << W) - 1), 0);
			}
 
		cout << dp[H][((1 << W) - 1)] << endl;
	}
	return 0;
}