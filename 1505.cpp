#include <iostream>
using namespace std;
int main() {
	char cha;
	cin >> cha;
	if (cha < 'x') cout << (char) (cha + 3) << endl;
	else if (cha == 'x') cout << "a" << endl;
	else if (cha == 'y') cout << "b" << endl;
	else cout << "c" << endl;
	return 0;
}