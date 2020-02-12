#include <cstdio>
#include <cstring>
#define MAX_N 2005
#define MAX_F 1005
const int K = (int)1e8;
int N, MOD, num;
int f[MAX_N][MAX_F];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - 48, ch = getchar();
    return res * flag;
}
int main() {
    N = read(); MOD = read();
    num = read(); num %= MOD; f[0][num] = 1;
    for (register int i = 1; i < N; ++i) {
        num = read();
        num %= MOD;
        for (register int j = 0; j < MOD; ++j) {
            int next = (j + num) % MOD;
            f[i][next] = (f[i - 1][j] + f[i - 1][next]) % K;
        }
        ++f[i][num];
    }
    int ans = 0;
    printf("%d\n", f[N - 1][0] % K);
    return 0;
}
