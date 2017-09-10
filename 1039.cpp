#include <iostream>
using namespace std;
const int MAX_N = 30010;
struct node {
	int lson = -1, rson = -1;
}a[MAX_N];
int num[MAX_N];
 
void findnum(int node, int nodenum) {
	
	if (a[node].lson != -1) findnum(a[node].lson, nodenum << 1);
	if (a[node].rson != -1) findnum(a[node].rson, nodenum << 1 | 1);
	num[node] = nodenum;
}
 
void output(int node) {
 
	if (a[node].lson != -1) output(a[node].lson);
	if (a[node].rson != -1) output(a[node].rson);
	cout << node << " ";
}
int main() {
 
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int temp, l, r;
		cin >> temp >> l >> r;
		a[temp].lson = l; a[temp].rson = r;
	}
	num[1] = 1;
	findnum(1, 1);
	for (int i = 1; i <= n; ++i) cout << num[i] << " ";
	cout << endl;
	output(1);
	return 0;
}