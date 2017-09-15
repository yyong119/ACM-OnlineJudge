#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
 
int const MAX_N = 110;
int main() {
	
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n;
	queue<int> next[MAX_N], cost[MAX_N];
	for (int i = 1; i < n; ++i) {
		int tmpx, tmpy, c;
		cin >> tmpx >> tmpy >> c;
		next[tmpx].push(tmpy); cost[tmpx].push(c);
		next[tmpy].push(tmpx); cost[tmpy].push(c);
	}
	cin >> m;
	while (m--) {
		int start, des, now, tmpcos;
		bool found = false, visited[MAX_N];
		memset(visited, false, sizeof(visited));
		cin >> start >> des;
		visited[start] = true;
		queue<int> que, cos, tmpnext, tmpcost;
		que.push(start);
		cos.push(0);
		while (true) {
			now = que.front();
			tmpcos = cos.front();
			que.pop(); cos.pop();
			tmpnext = next[now]; tmpcost = cost[now];
			while (!tmpnext.empty()) {
				int nextnode = tmpnext.front(), nextcost = tmpcos + tmpcost.front();
				tmpnext.pop(); tmpcost.pop();
				if (nextnode == des) {
					found = true;
					cout << nextcost << endl;
					break;
				}
				if (!visited[nextnode]) {
					que.push(nextnode); cos.push(nextcost);
					visited[nextnode] = true;
				}
			}
			if (found) break;
		}
	}
	return 0;
}