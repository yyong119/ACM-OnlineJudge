#include <iostream>
#include <cmath>
using namespace std;
int n;
bool flag = true;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int tmp = n;
	while (tmp) {
		if (tmp % 10 != 7 && tmp % 10 != 4) {
			flag = false;
			break;
		}
		tmp /= 10;
	}
	if (flag)
		for (int i = 2; i <= sqrt(n); ++i)
			if (n % i == 0) {
				flag = false;
				break;
			}
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}