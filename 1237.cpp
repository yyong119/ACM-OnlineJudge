#include <cstdio>
#include <queue>
using namespace std;
int n, m, pr, ne, now, next, maxnum;
int indegree[10001];
queue<int> que[2], point[10001];
 
void topo(int depth, int state) {
 
    if (que[state].empty()) {
        maxnum = max(maxnum, depth - 1);
        return;
    }
    while (que[state].size()) {
        now = que[state].front(); que[state].pop();
        while (point[now].size()) {
            next = point[now].front();
            indegree[next]--;
            if (indegree[next] == 0) que[1 - state].push(next);
            point[now].pop();
        }
    }
    topo(depth + 1, 1 - state);
}
 
int main() {
 
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &ne, &pr);
        point[pr].push(ne);
        indegree[ne]++;
    }
    for (int i = 1; i <= n; i++)
        if (!indegree[i]&&point[i].size()) que[0].push(i);
    maxnum = 1;
    topo(1, 0);
    printf("%d\n", maxnum);
    return 0;
}