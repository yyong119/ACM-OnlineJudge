#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	int inTime, outTime;
}a[5005];

bool cmp(const node &p, const node &q) {
	return p.inTime < q.inTime;
}

int main() {

	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].inTime, &a[i].outTime);
	sort(a, a + n, cmp);
	int maxNotEmptyTime = 0, maxEmptyTime = 0;
	int currentStart = a[0].inTime, currentEnd = a[0].outTime;
	for (int i = 1; i < n; ++i) {
		if (a[i].inTime > currentEnd) {
			maxNotEmptyTime = max(maxNotEmptyTime, currentEnd - currentStart);
			maxEmptyTime = max(maxEmptyTime, a[i].inTime - currentEnd);
			currentStart = a[i].inTime;
		}
		currentEnd = max(currentEnd, a[i].outTime);
	}
	maxNotEmptyTime = max(maxNotEmptyTime, currentEnd - currentStart);
	printf("%d %d\n", maxNotEmptyTime, maxEmptyTime);
	return 0;
}
