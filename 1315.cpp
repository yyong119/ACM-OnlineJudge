#include<algorithm>
#include <iostream>
 
using namespace std;
 
struct Item {
	double a;
	double b;
}p[40000];
 
bool check(int a, int b) {
	for (int i = 2; i <= min(a, b); i++)
		if (a%i == 0 && b%i == 0)return false;
	return true;
}
 
bool cmp(Item A, Item B) {
	return A.a / A.b < B.a / B.b;
}
 
int main() {
 
	ios::sync_with_stdio(false);
	int n, t = 0;
	cin >> n;
	cout << "0/1" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j<i; j++) {
			if (i % 2 == 0 && j % 2 == 0)continue;
			if (check(i, j)) {
				p[t].a = j; p[t++].b = i;
			}
		}
	}
	sort(p, p + t, cmp);
	for (int i = 0; i < t; i++) cout << (int)p[i].a << "/" << (int)p[i].b << endl;
	cout << "1/1" << endl;
	return 0;
}