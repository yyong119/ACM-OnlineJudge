#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define MAX_N 505
#define MAX_S 2010
using namespace std;
int n, sum;
int a[MAX_N];
int f[MAX_N][MAX_S];// f_ij: max height when diff is j with 1~i toothpicks
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
int main() {
    n = read();
    for (register int i = 1; i <= n; ++i) a[i] = read();
    for (register int i = 1; i <= n; ++i) {
        sum += a[i];
        memcpy(f[i], f[i - 1], sizeof(f[0]));
        for (register int j = 0; j <= sum; ++j) {
            // height will at least be j when the diff is j
            if (f[i - 1][j] < j) continue;
            // add i-th toothpick to the longer side
            int diff = j + a[i];
            f[i][diff] = max(f[i][diff], f[i - 1][j] + a[i]);
            // ... shorter side
            diff = abs(j - a[i]);
            f[i][diff] = max(f[i][diff], f[i - 1][j] + a[i]);
        }
    }
    if (f[n][0]) printf("%d\n", f[n][0] >> 1);
    else printf("Impossible");
    return 0;
}