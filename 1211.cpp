#include <cstdio>
#include <queue>
using namespace std;

const int MAX_N = 100000;
struct node_data {
	int left_child, right_child, father;
} node[MAX_N + 10];

int main() {

	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int tmp_left, tmp_right; scanf("%d%d", &tmp_left, &tmp_right);
		node[i].left_child = tmp_left;
		node[tmp_left].father = i;
		node[i].right_child = tmp_right;
		node[tmp_right].father = i;
	}

	int root = 1;
	while (node[root].father) root = node[root].father;
	queue<int> que; que.push(root);
	int cnt = 1; bool flag = true;

	while (!que.empty()) {
		int tmp = que.front(); que.pop();
		if (node[tmp].left_child) {
			que.push(node[tmp].left_child);
			++cnt;
		}
		else if(cnt < n) {
			flag = false; break;
		}
		if (node[tmp].right_child) {
			que.push(node[tmp].right_child);
			++cnt;
		}
		else if (cnt < n) {
			flag = false; break;
		}
	}
	if (flag) printf("%c\n", 'Y'); else printf("%c\n", 'N');

	return 0;
}
