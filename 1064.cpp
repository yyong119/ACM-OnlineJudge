#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 5010;
int n, ans = 1;
int a[MAX_N], num[MAX_N], f[MAX_N], cnt[MAX_N][110], check[MAX_N << 2];

void add(int *x, int *y) {

    int carries = 0, length = 1, z[110] = {0};
    while (length <= x[0] || length <= y[0]) {
        z[length] = x[length] + y[length] + carries;
        carries = z[length] / 10;
        z[length] = z[length] % 10;
        length++;
    }
    z[length] = carries;
    if (!z[length]) length--;
    x[0] = length;
    for (int i = 1; i <= length; ++i) x[i] = z[i];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        f[i] = 1;
    }
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            if (a[i] < a[j]) f[i] = max(f[i], f[j] + 1);
    for (int i = 1; i <= n; ++i) ans = max(ans, f[i]);
    printf("%d ", ans);

    for (int i = 1; i <= n; ++i) {
        if (f[i] == 1) cnt[i][0] = cnt[i][1] = 1;
        else {
            memset(check, 0, sizeof(check));
            cnt[i][0] = 1;
            for (int j = i - 1; j > 0; --j)
                if (f[j] + 1 == f[i] && !check[a[j]] && a[i] < a[j]) {
                    add(cnt[i], cnt[j]);
                    check[a[j]] = 1;
                }
        }
    }
    memset(check, 0, sizeof(check));
    for (int i = n; i > 0; --i)
        if (f[i] == ans && !check[a[i]]) {
            add(num, cnt[i]);
            check[a[i]] = 1;
        }
    for (int i = num[0]; i >= 1; --i) printf("%d", num[i]);
    return 0;
}
