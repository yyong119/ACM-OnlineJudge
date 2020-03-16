#include <cstdio>
#include <queue>
#include <algorithm>
// #include <map>
#define MAX_N 200010
#define KEY 10000007
using namespace std;
struct Node {
    int x, y, v;
    Node(int i = 0, int j = 0, int p = 0): x(i), y(j), v(p) {}
    bool operator<(const Node &p) const {
        return v > p.v;
    }
};
int n;
int a[MAX_N], b[MAX_N];
bool my_hash[KEY];
// map<long long, bool> um;
priority_queue<Node> q;
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i) a[i] = read();
    for (register int i = 0; i < n; ++i) b[i] = read();
    sort(a, a + n); sort(b, b + n);
    q.push(Node(0, 0, a[0] + b[0]));
    for (register int i = 0; i < n; ++i) {
        // print the current minimun
        Node cur = q.top(); printf("%d\n", cur.v); q.pop();
        // solve for next possible numbers
        int x_c = cur.x, x_n = x_c + 1, y_c = cur.y, y_n = y_c + 1;
        long long x_p = ((long long) x_n << 18) | y_c, y_p = ((long long) x_c << 18) | y_n;
        int x_p_m = x_p % KEY, y_p_m = y_p % KEY;
        // (x_n, y_c) is valid and has not been in queue
        // if (x_n < n && um.find(x_p) == um.end()) {
        if (x_n < n && !my_hash[x_p_m]) {
            q.push(Node(x_n, y_c, a[x_n] + b[y_c]));
            // um[x_p] = true;
            my_hash[x_p_m] = true;
        }
        // (x_c, y_n) is valid and has not been in queue
        // if (y_n < n && um.find(y_p) == um.end()) {
        if (y_n < n && !my_hash[y_p_m]) {
            q.push(Node(x_c, y_n, a[x_c] + b[y_n]));
            // um[y_p] = true;
            my_hash[y_p_m] = true;
        }
    }
    return 0;
}
