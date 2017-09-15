#include <iostream>
using namespace std;
int main() {
	
	ios::sync_with_stdio(false);
	int n, total = 0;
	cin >> n;
	while (n--) {
		long tmp;
		cin >> tmp;
		if (tmp < 0) tmp = -tmp;
		while (tmp) {
			total += tmp % 2;
			tmp /= 2;
		}
	}
	cout << total << endl;
	return 0;
}