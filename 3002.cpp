#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000;
int main() {
	int n, temp, num = 0;
	int a[MAXN + 1];
	memset(a, 0, sizeof(a));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> temp;
		if (a[temp] == 0) {
			++num;
			++a[temp];
		}
	}
	cout << num << endl;
	for (int i = 1; i <= MAXN; ++i) if (a[i]) cout << i << " ";
}