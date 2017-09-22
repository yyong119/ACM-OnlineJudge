#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
 
using namespace std;
 
int n, m, s, e, temp1, temp2, temp3, now, next;
int dist[101];
int nextnode[101][101];
int nodeweight[101][101];
bool inque[101];
int main() {
 
    queue<int> que;
    memset(inque, false, sizeof(inque));
    scanf("%d%d%d%d\n", &n, &m, &s, &e);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &temp1, &temp2, &temp3);
        nextnode[temp1][++nextnode[temp1][0]] = temp2;
        nodeweight[temp1][++nodeweight[temp1][0]] = temp3;
    }
    for (int i = 1; i <= n; i++) dist[i] = 10000000;
    dist[s] = 0; inque[s] = true;
    que.push(s);
    while (!que.empty()) {
        now = que.front();
        for (int i = 1; i <= nextnode[now][0]; i++) {
            next = nextnode[now][i];
            if (dist[next] > dist[now] + nodeweight[now][i]) {
                dist[next] = dist[now] + nodeweight[now][i];
                if (!inque[next]) {
                    inque[next] = true;
                    que.push(next);
                }
            }
        }
        que.pop(); inque[now] = false;
    }
    printf("%d\n", dist[e]);
    return 0;
}