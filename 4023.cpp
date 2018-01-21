#include <iostream>
using namespace std;

const int MAX_N = 100;
int a[MAX_N + 5];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		int tmp = 0;
		for (int j = 0; j < i; ++j)
			if (a[j] < a[i]) ++tmp;
		cout << tmp << " ";
	}
	return 0;
}
