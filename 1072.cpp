#include <iostream>
#define MAX_N 20005
using namespace std;
int n;
int a[MAX_N * 5], tree[MAX_N * 5];
int map[MAX_N][6];
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
void update(int x, int num) {
    for (; x <= n * 5; x += x & -x)
        tree[x] = max(tree[x], num);
}
int query(int x) {
    int res = 0;
    for (; x; x -= x & -x)
        res = max(res, tree[x]);
    return res;
}
int main() {
    n = read();
    for (int i = 1; i <= n * 5; ++i) a[i] = read();
    for (int i = 1; i <= n * 5; ++i) {
        int tmp = read();
        map[tmp][++map[tmp][0]] = i;
    }
    for (int i = 1; i <= n * 5; ++i)
        for (int j = 5; j >= 1; --j)
            update(map[a[i]][j], query(map[a[i]][j] - 1) + 1);
    cout << query(n * 5) << endl;
    return 0;
}
