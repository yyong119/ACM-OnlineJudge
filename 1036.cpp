#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100005];
long long total[3], sum[3];

int getMinIndex() {

	if (sum[0] <= sum[1] && sum[0] <= sum[2]) return 0;
	else if (sum[1] <= sum[0] && sum[1] <= sum[2]) return 1;
	else return 2;
}

int main() {

	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	for (int i = 0; i < n; i += 3) {
		total[0] += sum[0];
		sum[0] += a[i];
	}
	for (int i = 1; i < n; i += 3) {
		total[1] += sum[1];
		sum[1] += a[i];
	}
	for (int i = 2; i < n; i += 3) {
		total[2] += sum[2];
		sum[2] += a[i];
	}
	long long totalTime = total[0] + total[1] + total[2];
	long long maxTime = max(max(sum[0], sum[1]), sum[2]);
	printf("%lld %lld\n", totalTime, maxTime);

	for (int i = 0; i < 3; ++i) {
		total[i] = 0; sum[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		int k = getMinIndex();
		total[k] += sum[k];
		sum[k] += a[i];
	}
	totalTime = total[0] + total[1] + total[2];
	maxTime = max(max(sum[0], sum[1]), sum[2]);
	printf("%lld %lld\n", totalTime, maxTime);

	return 0;

}
