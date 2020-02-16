#include <cstdio>
#include <iostream>
#define MAX_N 50010
int n, cur_max_id, x;
int a[MAX_N];
char op;
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
int main() {
    n = read();
    op = getchar();
    while (op != 'f') {
        if (op == 'q') {
            printf("%d %d\n", cur_max_id, a[cur_max_id]);
            while (op != '\n') op = getchar();
        }
        else if (op == 'a') {
            read(); x = read();
            ++a[x];
            if (a[x] > a[cur_max_id] || a[x] == a[cur_max_id] && x < cur_max_id) {
                cur_max_id = x;
            }
        }
        op = getchar();
    }
    return 0;
}
