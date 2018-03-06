#include <cstdio>
#include <queue>
using namespace std;

const int MAX_N = 100000;
struct node_data {
	int left_child, right_child, father, value;
} node[MAX_N + 10];

int main() {

	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int tmp_left, tmp_right, tmp_value; scanf("%d%d%d", &tmp_left, &tmp_right, &tmp_value);
		node[i].value = tmp_value;
		node[i].left_child = tmp_left; node[tmp_left].father = i;
		node[i].right_child = tmp_right; node[tmp_right].father = i;
	}

	int root = 1;
	while (node[root].father) root = node[root].father;
	queue<int> que; que.push(root);

	while (!que.empty()) {
		int tmp = que.front(); que.pop();
		printf("%d ", node[tmp].value);
		if (node[tmp].left_child) que.push(node[tmp].left_child);
		if (node[tmp].right_child) que.push(node[tmp].right_child);
	}

	return 0;
}
