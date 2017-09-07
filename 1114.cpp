#include <cstdio>
#include <algorithm>
#define MAX 300010
using namespace std;
const int INF = 0xFFFFFFF;
int nums[MAX], sorted[MAX], root[MAX];
int cnt;
struct TMD {
	int sum, L_son, R_son;
} Tree[MAX << 5];
 
inline int CreateNode(int _sum, int _L_son, int _R_son) {
 
	int idx = ++cnt;
	Tree[idx].sum = _sum;
	Tree[idx].L_son = _L_son;
	Tree[idx].R_son = _R_son;
	return idx;
}
 
void Insert(int & root, int pre_rt, int pos, int L, int R) {
 
	root = CreateNode(Tree[pre_rt].sum + 1, Tree[pre_rt].L_son, Tree[pre_rt].R_son);
	if (L == R) return;
	int M = (L + R) >> 1;
	if (pos <= M)
		Insert(Tree[root].L_son, Tree[pre_rt].L_son, pos, L, M);
	else
		Insert(Tree[root].R_son, Tree[pre_rt].R_son, pos, M + 1, R);
}
 
int Query(int S, int E, int L, int R, int K) {
 
	if (L == R) return L;
	int M = (L + R) >> 1;
	int sum = Tree[Tree[E].L_son].sum - Tree[Tree[S].L_son].sum;
	if (K <= sum)
		return Query(Tree[S].L_son, Tree[E].L_son, L, M, K);
	else
		return Query(Tree[S].R_son, Tree[E].R_son, M + 1, R, K - sum);
}
 
int main() {
 
	int n, m, num, pos, T;
	scanf("%d", &n);
	cnt = 0; root[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &nums[i]);
		sorted[i] = nums[i];
	}
	sort(sorted + 1, sorted + 1 + n);
	num = unique(sorted + 1, sorted + n + 1) - (sorted + 1);
	for (int i = 1; i <= n; ++i) {
		pos = lower_bound(sorted + 1, sorted + num + 1, nums[i]) - sorted;
		Insert(root[i], root[i - 1], pos, 1, num);
	}
	scanf("%d", &m);
	int l, r, k;
	while (m--) {
		scanf("%d %d %d", &l, &r, &k);
		pos = Query(root[l - 1], root[r], 1, num, k);
		printf("%d\n", sorted[pos]);
	}
	return 0;
}