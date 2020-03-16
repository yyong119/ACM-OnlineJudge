#include <cstdio>
#define MAX_N 25
#define MAX_M 25
#define OFFSET 7510
#define MAX_LEN 30
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;
int n, m;
int pos[MAX_M], w[MAX_N];
struct LONGINT {
    int len;
    int num[MAX_LEN];
    LONGINT(): len(1) {}
    LONGINT operator+=(const LONGINT &p) {
        int length_m = max(len, p.len);
        // add p to this
        for (register int i = 0; i < length_m; ++i) {
            num[i] += p.num[i];
            if (num[i] > 9) {
                ++num[i + 1];
                num[i] -= 10;
            }
        }
        len = (num[length_m] ? length_m + 1 : length_m);
        return *this;
    }
} f[MAX_N][OFFSET << 1];
// long long f[MAX_N][OFFSET << 1];
int main() {
    scanf("%d %d", &m, &n);
    for (register int i = 0; i < m; ++i) scanf("%d", &pos[i]);
    for (register int i = 1; i <= n; ++i) scanf("%d", &w[i]);
    f[0][OFFSET].num[0] = 1;
    // dp
    for (register int i = 1; i <= n; ++i)
        for (register int j = 0; j < (OFFSET << 1); ++j)
            for (register int k = 0; k < m; ++k) {
                // put the i-th socks to k-th hook
                int prev_state = j - w[i] * pos[k];
                if (prev_state >= 0 && prev_state < (OFFSET << 1))
                    f[i][j] += f[i - 1][prev_state];
            }
    // output
    for (register int i = f[n][OFFSET].len - 1; i > -1; --i)
        printf("%d", f[n][OFFSET].num[i]);
    return 0;
}
