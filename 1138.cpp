#include <cstdio>
#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX_N 10010
#define MAX_K 25
using namespace std;
struct Node {
    int tar, time;
    Node(int a = 0, int b = 0): tar(a), time(b) {}
};
int N, M, K;
int f[MAX_N][MAX_K];
vector<Node> link[MAX_N];
deque<int> q;
bool inque[MAX_N];
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
inline bool cmp(const Node &p, const Node &q) {
    return p.time < q.time;
}
int main() {
    N = read(); M = read(); K = read();
    memset(f, 0x3f3f3f3f, sizeof(f));
    f[1][0] = 0;
    for (register int i = 0; i < M; ++i) {
        int x = read(), y = read(), t = read();
        link[x].push_back(Node(y, t));
        link[y].push_back(Node(x, t));
    }
    for (register int i = 0; i < N; ++i)
        sort(link[i].begin(), link[i].end(), cmp);
    q.push_back(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop_front(); inque[cur] = false;
        for (register int i = 0; i < link[cur].size(); ++i) {
            int next = link[cur][i].tar, cost = link[cur][i].time;
            bool flag = false;
            for (register int j = 0; j <= K; ++j)
                if (f[cur][j] + cost < f[next][j]) {
                    f[next][j] = f[cur][j] + cost;
                    flag = true;
                }
            for (register int j = 0; j < K; ++j)
                if (f[cur][j] < f[next][j + 1]) {
                    f[next][j + 1] = f[cur][j];
                    flag = true;
                }
            if (!inque[next] && flag) {
                if (!q.empty() && f[next][K] >= f[q.front()][K]) q.push_back(next);
                else q.push_front(next);
                inque[next] = true;
            }
        }
    }
    printf("%d\n", f[N][K]);
    return 0;
}
