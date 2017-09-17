#include <cmath>
#include <iostream>
using namespace std;
int main() {
	float x1, x2, y1, y2, deltax, deltay;
	cin >> x1 >> y1 >> x2 >> y2;
	deltax = abs(x1 - x2); deltay = abs(y1 - y2);
	float ans = sqrt(deltax * deltax + deltay * deltay);
	cout.precision(6);
	cout << ans << endl;
	return 0;
}