#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 705
#define INF 0x3f3f3f3f
using namespace std;

int n;
int x[MAX_N], y[MAX_N];

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	int max = 2;
	for (int i = 0; i < n; ++i) {
		double tan[n];
		memset(tan, 0, sizeof(tan));
		tan[i] = INF + 1;
		for (int j = 0; j < n; ++j)
			if (i != j)
				if (x[i] == x[j])
					tan[j] = INF;
				else
					tan[j] = (double)(y[j] - y[i]) / (x[j] - x[i]);

		sort(tan, tan + n);
		int tmp_max = 0, cnt = 1;
		for (int j = 1; j < n; ++j)
			if (tan[j] == tan[j - 1])
				++cnt;
			else {
				if (cnt > tmp_max)
					tmp_max = cnt;
				cnt = 1;
			}
		if (tmp_max + 1 > max) max = tmp_max + 1;
	}
	cout << max << endl;
	return 0;
}