#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_T 1010
#define MAX_M 105
using namespace std;
int t, m;
struct Node {
    int time, value;
} a[MAX_M];
int f[MAX_T];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
int main() {
    t = read(); m = read();
    for (register int i = 0; i < m; ++i)
        a[i].time = read(), a[i].value = read();
    for (register int i = 0; i < m; ++i)
        for (register int j = t; j >= a[i].time; --j)
                f[j] = max(f[j], f[j - a[i].time] + a[i].value);

    printf("%d\n", f[t]);
    return 0;
}
