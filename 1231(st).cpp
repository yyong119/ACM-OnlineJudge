#include <iostream>
#include <cmath>
using namespace std;

const int MAX_N = 110;
struct node {
	int depth, index;
} dp[MAX_N << 5][20];
struct tree {
	int left, right;
} Tree[MAX_N];
int firstMeet[MAX_N];
int N, X, Y, total;

int log2(const int &p) {
	return (int)(log(p) / log(2));
}

void dfs(int root, int depth) {
	dp[++total][0].depth = depth; dp[total][0].index = root;
	if (!firstMeet[root]) firstMeet[root] = total;
	if (Tree[root].left) {
		dfs(Tree[root].left, depth + 1);
		dp[++total][0].depth = depth; dp[total][0].index = root;
	}
	if (Tree[root].right) {
		dfs(Tree[root].right, depth + 1);
		dp[++total][0].depth = depth; dp[total][0].index = root;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin >> N >> X >> Y;
	for (int i = 1; i <= N; ++i) cin >> Tree[i].left >> Tree[i].right;

	dfs(1, 1);

	for (int pw = 1; pw <= log2(total); ++pw) {
		int len = 1 << pw, halflen = 1 << (pw - 1);
		for (int i = 1; i <= total - len + 1; ++i)
			if (dp[i][pw - 1].depth < dp[i + halflen][pw - 1].depth)
				dp[i][pw] = dp[i][pw - 1];
			else dp[i][pw] = dp[i + halflen][pw - 1];
	}

	/*for (int i = 1; i <= total; ++i) cout << dp[i][1].depth << ' ' << dp[i][1].index << endl;
	cout << firstMeet[X] << ' ' << firstMeet[Y] << endl;*/

	int l, r;
	if (firstMeet[Y] < firstMeet[X]) {
		l = firstMeet[Y]; r = firstMeet[X];
	}
	else {
		l = firstMeet[X]; r = firstMeet[Y];
	}

	int length = r - l + 1, pw = log2(length), len = 1 << pw;
	//cout << dp[l][pw].depth << ' ' << dp[l][pw].index << endl;
	//cout << dp[r - len + 1][pw].depth << ' ' << dp[r - len + 1][pw].index << endl;
	if (dp[l][pw].depth < dp[r - len + 1][pw].depth)
		cout << dp[l][pw].index;
	else cout << dp[r - len + 1][pw].index;

	//system("pause");
	return 0;
}
