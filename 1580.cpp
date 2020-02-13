#include <cstdio>
#include <iostream>
#define MAX_N 1000010
using namespace std;
int n, len, tmp;
int lis[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
int main() {
    n = read(); tmp = read(); lis[++len] = tmp;
    for (register int i = 1; i < n; ++i) {
        tmp = read();
        if (tmp > lis[len]) lis[++len] = tmp;
        else {
            int pos = lower_bound(lis, lis + len, tmp) - lis;
            lis[pos] = tmp;
        }
    }
    printf("%d", len);
    return 0;
}
