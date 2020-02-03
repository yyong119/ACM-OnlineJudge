#include <cstdio>
#define MAX_N 100010
using namespace std;

long long a[MAX_N], sum[MAX_N];
int N, F;

int main() {

	scanf("%d%d", &N, &F);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &(a[i]));
		sum[i] = sum[i - 1] + a[i];
	}
	double res = -1;
	for (int j = 0, i = 0; i + F <= N; i++) {
		if (i > j && ((sum[i] - sum[j]) * (i + F - j) < (sum[i + F] - sum[j]) * (i - j)))
			j = i;
		if (res * (i - j + F) < sum[i + F] - sum[j])
			res = (double)(sum[i + F] - sum[j]) / (i - j + F);
	}
	printf("%d\n", (int)(1000 * res));
	return 0;
}