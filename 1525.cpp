#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX_N = 3000010;
int a[MAX_N];
int main() {
 
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	printf("%d\n", a[k - 1]);
	return 0;
}