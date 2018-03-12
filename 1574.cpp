#include<iostream>

using namespace std;

int PowerMod(long long a, long long b, long long c) {

	long long ans = 1;
	a %= c;
	for (; b; b >>= 1) {
		if (b % 2) ans = (ans * a) % c;
		a = a * a % c;
	}
	return ans % c;
}

int main() {

    ios::sync_with_stdio(false);

	long long n, m, k, x;
	cin >> n >> m >> k >> x;

	long long ans = PowerMod(10, k, n);
	ans = (ans * m % n + x) % n;
	cout << ans;

	return 0;
}
