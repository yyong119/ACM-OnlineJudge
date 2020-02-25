#include<cstdio>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define MAX_N 3000010
using namespace std;
int n, k, ans, h1, t1 = -1, h2, t2 = -1, tmp;
int a[MAX_N], q1[MAX_N],q2[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
int main() {
    k = read(); n = read();
    for (register int i = 0; i < n; ++i) {
        a[i] = read();
        // q1 interval maximum
        while (h1 <= t1 && a[i] >= a[q1[t1]]) --t1;
        // q2 interval minimum
        while (h2 <= t2 && a[i] <= a[q2[t2]]) --t2;
        // enqueue
        q1[++t1] = i; q2[++t2] = i;
        while (a[q1[h1]] - a[q2[h2]] > k)
            tmp = q1[h1] < q2[h2] ? q1[h1++] + 1 : q2[h2++] + 1;
            // if (q1[h1] < q2[h2]) tmp = q1[h1++] + 1;
            // else tmp = q2[h2++] + 1;
        ans = max(ans, i - tmp);
    }
    printf("%d", ans + 1);
}
