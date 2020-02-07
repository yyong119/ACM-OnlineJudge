#include <cstdio>
#include <algorithm>
#define MAX_H 35000
using namespace std;
int n, init_H, init_I;
int f[MAX_H];
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
int main() {
    n = read(); init_H = read(); init_I = read();
    for (register int i = 0; i < MAX_H; ++i)
        f[i] = -MAX_H;//智力中间可负，需要初始化为负数，不然会卡第2个测试点
    f[init_H] = init_I;
    for (register int i = 0; i < n; ++i) {
        int health = read(), intell = read();
        if (health < 0 && intell < 0) continue;
        if (health > 0) {
            for (register int j = MAX_H - 1; j >= health; --j)
                if (f[j - health] > -MAX_H)
                    f[j] = max(f[j], f[j - health] + intell);
        }
        else {
            for (register int j = 0; j < MAX_H + health; ++j)
                if (f[j - health] > -MAX_H)
                    f[j] = max(f[j], f[j - health] + intell);
        }
    }
    int ans = 0;
    for (register int i = 1; i < MAX_H; ++i)
        if (f[i] > 70) ans = max(ans, i * f[i]);
    if (ans)
        printf("%d\n", ans);
    else
        printf("Death");
    return 0;
}
