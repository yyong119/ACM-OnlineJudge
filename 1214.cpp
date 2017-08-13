#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_N = 100010;
struct node {
	int lson = 0, rbro = 0, value = 0;
};
node a[MAX_N];
 
void preorder(int t) {
 
	cout << a[t].value << " ";
	if (a[t].lson) preorder(a[t].lson);
	if (a[t].rbro) preorder(a[t].rbro);
}
 
void postorder(int t) {
 
	if (a[t].lson) postorder(a[t].lson);
	cout << a[t].value << " ";
	if (a[t].rbro) postorder(a[t].rbro);
}
 
void level(queue<int> t) {
 
	queue<int> next;
	while (!next.empty()) next.pop();
	while (!t.empty()) {
		int temp = t.front();
		t.pop(); cout << a[temp].value << " ";
		if (a[temp].lson) {
			next.push(a[temp].lson);
			int temp2 = a[a[temp].lson].rbro;
			while (temp2) {
				next.push(temp2);
				temp2 = a[temp2].rbro;
			}
		}
	}
	if (!next.empty()) level(next);
}
 
int main() {
 
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int pre[MAX_N]; memset(pre, 0, sizeof(pre));
	for (int i = 1; i <= n; ++i) {
		int temp, lson, rbro;
		cin >> lson >> rbro >> temp;
		a[i].lson = lson;
		a[i].rbro = rbro;
		a[i].value = temp;
		pre[lson] = i;
		if (rbro) {
			pre[rbro] = pre[i] = -1;
		}
	}
	int root;
	for (root = 1; root <= n; ++root) if (pre[root] == 0) break;
 
	preorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	queue<int> p; p.push(root);
	level(p);
	cout << endl;
	return 0;
}