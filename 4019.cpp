#include <cstdio>
#include <vector>
#include <queue>
#define MAX_N 20005
using namespace std;
int n, a, b, c;
vector<int> adj[MAX_N], dist[MAX_N];
int dist_from_a[MAX_N], dist_from_b[MAX_N], dist_from_c[MAX_N];

void find_dist(int p, int dist_from_p[]) {
    
    queue<int> que;
    while (!que.empty()) que.pop();
    que.push(p);
    while(!que.empty()) {
        int cur = que.front(); que.pop();
        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i];
            if (!dist_from_p[next]) {
                dist_from_p[next] = dist_from_p[cur] + dist[cur][i];
                que.push(next);
            }
        }
    }
}

int main() {

    scanf("%d%d%d%d", &n, &a, &b, &c);
    for (int i = 1; i < n; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back(v); dist[u].push_back(c);
        adj[v].push_back(u); dist[v].push_back(c);
    }
    find_dist(a, dist_from_a);
    find_dist(b, dist_from_b);
    find_dist(c, dist_from_c);
    dist_from_a[a] = 0;
    dist_from_b[b] = 0;
    dist_from_c[c] = 0;
    // for (int i = 1; i <= n; ++i) {
    //     printf("%d %d %d\n", dist_from_a[i], dist_from_b[i], dist_from_c[i]);
    // }
    int p, min_dist = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        int total_dist = dist_from_a[i] + dist_from_b[i] + dist_from_c[i];
        if (total_dist < min_dist) {
            min_dist = total_dist;
            p = i;
        }
    }
    printf("%d\n%d\n", p, min_dist);
    return 0;
}