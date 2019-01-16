#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	char square1[n][n], square2[n][n];

	for (int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> square1[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> square2[i][j];

	int flag = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (square1[i][j] != square2[j][n - 1 - i])
				flag = 0;
	if (flag) {
		cout << 1 << endl;
		return 0;
	}

	flag = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (square1[i][j] != square2[n - 1 - i][n - 1 - j])
				flag = 0;
	if (flag) {
		cout << 2 << endl;
		return 0;
	}

	flag = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (square1[i][j] != square2[n - 1 - j][i])
				flag = 0;
	if (flag) {
		cout << 3 << endl;
		return 0;
	}

	flag=1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (square1[i][j] != square2[i][n - 1 - j])
				flag = 0;
	if (flag) {
		cout << 4 << endl;
		return 0;
	}

    int s1 = 1, s2 = 1, s3 = 1;
    flag = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (square1[i][j] != square2[j][i])
				s1 = 0;
            if (square1[i][j] != square2[n - 1 - i][j])
				s2 = 0;
            if (square1[i][j] != square2[n - 1 - j][n - 1 - i])
				s3 = 0;
        }
	if (s1 || s2 || s3) {
		cout << 5 << endl;
		return 0;
	}

	flag = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (square1[i][j] != square2[i][j])
				flag = 0;
	if (flag)
		cout << 6 << endl;
	else
		cout << 7 << endl;
	return 0;
}
