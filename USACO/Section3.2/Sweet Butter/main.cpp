/*
ID: forusac5
PROG: butter
LANG: C++
*/
#include <queue>
#include <cstdio>
#include <utility>
#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>
#include <map>
#include <cassert>
#define MMset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int MAXP = 810;
int cnt[MAXP], dist[MAXP];
bool in[MAXP];
vector <pair<int, int> > adj[MAXP];
int N, P, C;
queue <int> Q;
void BFS(int start) {
    MMset(in, 0);
    MMset(dist, 0x7f);
    dist[start] = 0;
    in[start] = 1;
    Q.push(start);
    while (!Q.empty()) {
        int u = Q.front();
        in[u] = 0;
        Q.pop();
        int len = adj[u].size();
        for (int i = 0; i < len; i++) {
            int v = adj[u][i].first;
            int cost = adj[u][i].second;
            if (dist[v] - cost > dist[u]) {
                dist[v] = cost + dist[u];
                if (!in[v]) {
                    in[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
}

int main()
{
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    scanf("%d%d%d", &N, &P, &C);
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        cnt[num]++;
    }
    for (int i = 0; i < C; i++) {
        int a, b, v;
        scanf("%d %d %d", &a, &b, &v);
        adj[a].push_back(make_pair(b, v));
        adj[b].push_back(make_pair(a, v));
    }
    int ret = 0x7fffffff;
    for (int i = 1; i <= P; i++) {
        BFS(i);
        int tot = 0;
        for (int j = 1; j <= P; j++) {
            tot += dist[j] * cnt[j];
        }
        ret = min(ret, tot);
    }
    printf("%d\n", ret);
    return 0;
}
