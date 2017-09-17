#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	double e[4];
	cin >> e[1] >> e[2] >> e[3];
	sort(e + 1, e + 4);
	if (e[1] + e[2] <= e[3]) cout << "not triangle" << endl;
	else if (e[1] * e[1] + e[2] * e[2] == e[3] * e[3]) cout << "right-angled triangle" << endl;
	else cout << "triangle" << endl;
	return 0;
}