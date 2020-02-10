#include <cstdio>
#include <cstring>
#define MAX_N 405
using namespace std;
int a[MAX_N][MAX_N];
int sum[MAX_N];
int N;
long long ans_odd;
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') ch = getchar();
    while (ch >= '0' && ch <= '9') res = ch - '0', ch = getchar();
    return res & 1;
}
void count_odd() {
    int cur = 0;
    int zeros[MAX_N]; zeros[0] = 0;
    register int i, j;
    for (i = 0; i < N; ++i) {
        ++cur;
        if (sum[i]) {
            zeros[++zeros[0]] = cur;
            cur = 0;
        }
    }
    if (!zeros[0]) return;
    zeros[++zeros[0]] = ++cur;
    for (i = 1; i < zeros[0]; ++i)
        for (j = i + 1; j <= zeros[0]; j += 2)
            ans_odd += zeros[i] * zeros[j];
}
int main() {
    scanf("%d", &N);
    register int i, j, k;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            a[i][j] = read();
    // calc from i-th row to j-th row
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) sum[j] = a[i][j];
        count_odd();
        for (j = i + 1; j < N; ++j) {
            for (k = 0; k < N; ++k) sum[k] = (sum[k] + a[j][k]) & 1;
            count_odd();
        }
    }
    printf("%lld %lld", ans_odd, (long long)N * N * (N + 1) * (N + 1) / 4 - ans_odd);
    return 0;
}
