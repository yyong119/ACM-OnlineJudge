#include <cstdio>
#include <cstring>
#define MAX_N 100010
#define MAX_M 5005
using namespace std;
int T, n, m;
int num[MAX_M];
inline int read() {
    register char ch = getchar(); register int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}

int main() {
    register long long ans;
    register int cur;
    T = read();
    while (T--) {
        memset(num, 0, sizeof(num));
        ans = 0; cur = 0;
        n = read(), m = read();
        for (register int i = 0; i < n; ++i) {
            cur = (cur + read()) % m;
            ++num[cur];
        }
        for (register int i = 0; i < m; ++i)
                ans += num[i] * (num[i] - 1) >> 1;
        ans += num[0];
        printf("%lld\n", ans);
    }
}
