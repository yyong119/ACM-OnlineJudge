#include <cstdio>
#define MAX_N 2000005
using namespace std;
int m, x;
long long ans[MAX_N];
int main() {
    for (register int n = 0; n < 100; ++n) {
        for (register int x = 0; x * 2 <= n; ++x)
            for (register int y = 0; x * 2 + y * 3 <= n; ++y)
                if ((n - x * 2 - y * 3) % 5 == 0) ++ans[n];
        // printf("n = %d ans = %d ", n, ans[n]);
        // if (n >= 10)
        //     printf("delta=%d", ans[n] - ans[n - 10]);
        // printf("\n");
    }
    for (register int i = 20; i < MAX_N; ++i)
        ans[i] = ans[i - 10] + ((i + 1) / 3);
    // for (register int i = 20; i < 100; ++i)
    //     printf("n = %d ans = %d\n", i, ans[i]);
    // printf("%lld %lld %lld\n", ans[90], ans[95], ans[99]);
    // printf("%lld %lld\n", ans[95], ans[99]);
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}
