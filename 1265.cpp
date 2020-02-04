#include <iostream>
#include <cstdio>
#define MAX_N 2050
using namespace std;
int n, op;
int tree[MAX_N][MAX_N];
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res;
}
void add(int x, int y, int num) {
    for (; x <= n; x += x & -x)
        for (int tmp_y = y; tmp_y <= n; tmp_y += tmp_y & -tmp_y)
            tree[x][tmp_y] += num;
}
int query(int x, int y) {
    int res = 0;
    for (; x; x -= x & -x)
        for (int tmp_y = y; tmp_y; tmp_y -= tmp_y & -tmp_y)
            res += tree[x][tmp_y];
    return res;
}
int main() {
    n = read(); op = read();
    while(op != 3) {
        if (op == 1) {
            int x = read(), y = read(), a = read();
            ++x; ++y;
            add(x, y, a);
        }
        else {
            int x1 = read(), y1 = read(), x2 = read(), y2 = read();
            ++x1; ++x2; ++y1; ++y2;
            printf("%d\n", query(x2, y2) + query(x1 - 1, y1 - 1) - query(x2, y1 - 1) - query(x1 - 1, y2));
        }
        op = read();
    }
    return 0;
}
