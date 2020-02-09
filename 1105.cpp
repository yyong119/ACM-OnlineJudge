#include <cstdio>
#include <deque>
#include <vector>
#include <cstring>
#define MAX_N 1010
using namespace std;
struct Node {
    int tar, val[3];
    Node(int a = 0, int b = 0, int c = 0, int d = 0): tar(a) {
        val[0] = b; val[1] = c; val[2] = d;
    }
};
int T, n, m, s, t;
vector<Node> link[MAX_N];
bool inque[MAX_N];
int dist[MAX_N];
deque<int> q;
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
void spfa(int idx) {
    q.push_back(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop_front(); inque[cur] = false;
        for (register int i = 0; i < link[cur].size(); ++i) {
            int next = link[cur][i].tar, cost = link[cur][i].val[idx];
            if (dist[cur] + cost < dist[next]) {
                dist[next] = dist[cur] + cost;
                if (!inque[next]) {
                    if (!q.empty() && dist[next] >= dist[q.front()]) q.push_back(next);
                    else q.push_front(next);
                    inque[next] = true;
                }
            }
        }
    }
}
int main() {
    T = read();
    while (T--) {
        for (register int i = 0; i < n; ++i) link[i].clear();
        n = read(); m = read(); s = read(); t = read();
        for (register int i = 0; i < m; ++i) {
            char ch; int data[5];
            for (int j = 0; j < 5; ++j) data[j] = read();
            link[data[0]].push_back(Node(data[1], data[2], data[3], data[4]));
            link[data[1]].push_back(Node(data[0], data[2], data[3], data[4]));
        }
        // calc minimun length
        memset(dist, 0x3f3f3f3f, sizeof(dist)); dist[s] = 0;
        memset(inque, false, sizeof(inque));
        spfa(0);
        printf("%d ", dist[t]);
        // calc minimun people
        memset(dist, 0x3f3f3f3f, sizeof(dist)); dist[s] = 0;
        memset(inque, false, sizeof(inque));
        spfa(1);
        printf("%d ", dist[t]);
        // calc minimun light
        memset(dist, 0x3f3f3f3f, sizeof(dist)); dist[s] = 0;
        memset(inque, false, sizeof(inque));
        spfa(2);
        printf("%d\n", dist[t]);
    }
    return 0;
}
