#include <cstdio>
#include <algorithm>
#define MAX_N 100005
using namespace std;
const int MOD = 1000000007;
int n, ans, p, q;
int a[MAX_N];
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i) a[i] = read();
    /*
        6个数有5个间隔，每个间隔分别被计算了
        1*5, 2*4, 3*3, 4*2, 5*1次
        下面的a[i]被更新为delta值，p, q分别是两个倍率
    */
    sort(a, a + n);
    for (register int i = 0; i < n; ++i) a[i] = a[i + 1] - a[i];
    p = 0, q = n;
    for (register int i = 0; i < n - 1; ++i) {
        ++p; --q;
        // 注: p, q, cur_ratio, ans直接用long long循环内只MOD一次会WA
        int cur_ratio = (long long)p * q % MOD;
        ans += (long long)cur_ratio * a[i] % MOD;
        ans %= MOD;
    }
    printf("%d\n", ans);
    return 0;
}
