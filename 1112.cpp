#include <cstdio>
#include <queue>
using namespace std;

int index[100005], relation[1005][1005], level[1005];
bool known[1005];
priority_queue<int> pri_que;

int main() {

	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &level[i]);//level[i]第i个人的知识水平
		index[level[i]] = i;//知识水平为level[i]的人的编号
	}
	for (int i = 1; i <= k; ++i) {
		int id; scanf("%d", &id);
		known[id] = true; pri_que.push(level[id]);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &relation[i][j]);

	while (!pri_que.empty()) {
		int asked_index = index[pri_que.top()];
		printf("%d\n", asked_index);
		pri_que.pop();
		for (int i = 1; i <= n; ++i)
			if (relation[i][asked_index] && !known[i]) {
				pri_que.push(level[i]);
				known[i] = true;
			}
	}

	return 0;
}
