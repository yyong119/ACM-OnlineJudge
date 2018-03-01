#include <cstdio>

int main() {

	long long sum = 0;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int tmp; scanf("%d", &tmp);
		sum += tmp;
	}

	printf("%lld", sum);
	return 0;
}