#include <iostream>
#include <queue>
#include <functional>
using namespace std;
 
int main() {
 
	priority_queue<int, vector<int>, greater<int> > que;
	int M; cin >> M;
	while (M--) {
		char op[20];
		cin >> op;
		switch (op[0]) {
		case 'i':
			int tmp; cin >> tmp; que.push(tmp); break;
		case 'd':
			que.pop(); break;
		case 'm':
			cout << que.top() << endl; break;
		}
	}
 
	return 0;
}