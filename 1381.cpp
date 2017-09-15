#include <iostream>
using namespace std;
 
//const int num[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
const int dataa[24] = {0,0,0,0,0,0,0,0,0,0,0,0,1,2,8,9,6,9,29,39,38,65,88,128};
int main() {
 
//	ios::sync_with_stdio(false);
//	int n, total = 0;
	int n;
	cin >> n;
/*	n -= 3;
	for (int i = 0; i < 999; ++i)
		for (int j = 0; j <= i; ++j) {
			int rest = n - 3, c = i - j, a = i, b = j;
			do {
				rest -= num[a % 10];
				a /= 10;
			} while (a);
			do {
				rest -= num[b % 10];
				b /= 10;
			} while (b);
			do {
				rest -= num[c % 10];
				c /= 10;
			} while (c);
			if (rest == 0) {
				++total;
			}
		}
	cout << total << endl;
*/
	cout << dataa[n] << endl;
	return 0;
}