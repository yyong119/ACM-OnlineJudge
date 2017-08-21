#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_N = 100010;
struct node {
	int key, num;
};
node a[MAX_N], b[MAX_N];
int Case;
 
inline bool cmp(node p, node q) { return p.key < q.key; }
 
int main() {
 
	scanf("%d", &Case);
	while (Case--) {
 
		long long ans = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].key, &a[i].num);
		for (int i = 0; i < m; ++i) scanf("%d%d", &b[i].key, &b[i].num);
		sort(a, a + n, cmp);
		sort(b, b + m, cmp);
 
		int j = 0; long long sum = 0;
		for (int i = 0; i < n; ++i) {
			for (; j < m; ++j) {
				if (a[i].key > b[j].key)
					sum += b[j].num;
				else break;
			}
			ans += sum * a[i].num;
		}
		printf("%lld\n", ans);
	}
	return 0;
}