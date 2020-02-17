#include <cstdio>
#define MAX_N 100010
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;
int n, m;
bool flag;
int a[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
int main() {
    n = read(), m = read();
    int l = 0, r = (int)1e9 + 5;
    for (register int i = 0; i < n; ++i) {
        a[i] = read();
        l = max(l, a[i]);
    }
    while (l < r) {
        int mid = (l + r) >> 1;
        flag = true;
        int cnt = 1, cur_sum = 0;
        for (register int i = 0; i < n; ++i)
            if (cur_sum + a[i] > mid) {
                cur_sum = a[i];
                ++cnt;
                if (cnt > m) {
                    flag = false; break;
                }
            }
            else cur_sum += a[i];
        if (flag) r = mid;
        else l = mid + 1;
    }
    printf("%d", l);
    return 0;
}
