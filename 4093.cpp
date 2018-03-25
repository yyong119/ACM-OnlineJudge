#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_M = 200010;
struct box{
	int pack, num;
}boxes[MAX_M];
int n, m, cnt;
long long ans;

bool cmp(const box &a, const box &b) {
	return a.num > b.num;
}

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) scanf("%d%d", &boxes[i].pack, &boxes[i].num);
	sort(boxes, boxes + m, cmp);
	for (int i = 0; i < m; ++i)
		if (boxes[i].pack <= n) {
			n -= boxes[i].pack;
			ans += (long long) boxes[i].pack * boxes[i].num;
		} else {
			ans += (long long) n * boxes[i].num;
			break;
		}
	printf("%lld\n", ans);
	return 0;
}