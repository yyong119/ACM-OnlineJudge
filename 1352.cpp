#include <iostream>
#include <cstring>
using namespace std;

long long n, m, sum, rest;
int flag;

int main() {

	cin >> m >> n;
	sum = m;
	rest = m;
	long long x[n];
	memset(x, 0, sizeof(x));
	
	for (int i = 0; i < n; ++i)
		cin >> x[i];

	for (int i = 0; i < n - 1; ++i) {

		if (rest < x[i]) {
			flag = 1;
			break;
		}
		long long change = rest / x[i];
		sum += change;
		rest = rest % x[i] + change;
	}

	if (!flag)
		while (rest >= x[n - 1]) {

			long long change = rest / x[n - 1];
			sum += change;
			rest = rest % x[n - 1] + change;
		}

	cout << sum << " " << rest << endl;

	return 0;
}
