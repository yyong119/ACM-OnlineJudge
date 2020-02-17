#include <cstdio>
#include <iostream>
#define MAX_N 100010
#define OFFSET 100010
using namespace std;
int n, B, B_pos;
int a[MAX_N];
int left_sum[MAX_N + OFFSET], right_sum[MAX_N + OFFSET];
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
int main() {
    n = read(), B = read();
    for (register int i = 0; i < n; ++i) {
        int tmp = read();
        if (tmp < B) a[i] = -1;
        else if (tmp > B) a[i] = 1;
        else B_pos = i;
    }
    int cur_sum = 0;
    for (register int i = B_pos - 1; i >= 0; --i) {
        cur_sum += a[i];
        ++left_sum[OFFSET + cur_sum];
    }
    cur_sum = 0;
    for (register int i = B_pos + 1; i < n; ++i) {
        cur_sum += a[i];
        ++right_sum[OFFSET - cur_sum];
    }
    long long ans = 1;
    for (register int i = 0; i < MAX_N + OFFSET; ++i)
        ans += left_sum[i] * right_sum[i];
    printf("%lld", ans + left_sum[OFFSET] + right_sum[OFFSET]);
    return 0;
}
