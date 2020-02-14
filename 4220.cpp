#include <iostream>
#include <cstdio>
#include <cmath>
#define MAX_N 200010
#define MAX_BIT 32
#define max(a, b) ((a) > (b) ? (a) : (b))
#define lowbit(x) ((x) & (-(x)))
using namespace std;
int a[MAX_N][MAX_BIT];
int pow_2[MAX_BIT];
int n, q;
inline int read() {
    int X = 0, w = 0; char ch = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return X;
}
inline void write(int x) {
    int y = 10, len = 1;
    while (y <= x) { y *= 10; len++; }
    while (len--) { y /= 10; putchar(x / y + 48); x %= y; }
    putchar('\n');
}
int main() {
    pow_2[0] = 1;
    for (int i = 1; i < MAX_BIT; ++i) pow_2[i] = pow_2[i - 1] << 1;
    n = read(), q = read();
    for (register int i = 1; i <= n; ++i) a[i][0] = read();
    for (register int j = 1; pow_2[j] <= n; ++j)
        for (register int i = 0; i + pow_2[j] - 1 <= n; ++i)
            a[i][j] = max(a[i][j - 1], a[i + pow_2[j - 1]][j - 1]);
 
    register int l, r, k;
    for (register int i = 0; i < q; ++i) {
        l = read(), r = read();
        k = log(r - l + 1) / 0.69314718;
        write(max(a[l][k], a[r - (1 << k) + 1][k]));
    }
    return 0;
}