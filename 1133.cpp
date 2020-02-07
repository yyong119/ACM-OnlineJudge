#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str;
int len;
long long ans_3, ans_2, ans_1;
long long s, t, a, r;
int main() {
    ios::sync_with_stdio(false);
	cin >> str;
	len = str.length();
    // calc ans_1
	for (int i = 0; i < len; ++i) {
		if (str[i] == 'S') ++s;
		if (str[i] == 'T') ++t;
		if (str[i] == 'A') ++a;
		if (str[i] == 'R') ++r;
	}
	ans_1 = s * t * a *r;
    // calc ans_2
    ans_2 = min(s, t);
    ans_2 = min(ans_2, a);
    ans_2 = min(ans_2, r);
    // calc ans_3
	s = t = a = r = 0;
	for (int i = 0; i < len; ++i) {
		if (str[i] == 'S') ++s;
		if (str[i] == 'T') ++t;
		if (str[i] == 'A') ++a;
		if (str[i] == 'R') ++r;
		t = min(s, t);
		a = min(t, a);
		r = min(a, r);
	}
	ans_3 = r;

    cout << ans_1 << " " << ans_2 << " " << ans_3;
	return 0;
}