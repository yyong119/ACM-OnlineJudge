#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define MAX_N 30
#define MAX_A 1000
using namespace std;
int n, sum, max_len, len;
int a[MAX_N];
bool vis[MAX_N], flag;
void find(int len) {
    int pos = upper_bound(a, a + n, len) - a;
    for (register int i = pos - 1; i >= 0; --i)
        if (!vis[i] && len - a[i] >= 0) {
            vis[i] = true;
            if (len - a[i] == 0) {
                flag = true; return;
            }
            find(len - a[i]);
            if (flag) return;
            vis[i] = false;
        }
}

int main() {
    scanf("%d", &n);
    for (register int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        max_len = max(max_len, a[i]);
    }
    sort(a, a + n);
    for (register int k = sum / max_len; k > 1; --k) {
        if (sum % k) continue;
        len = sum / k;
        // check for k and len
        memset(vis, false, sizeof(vis));
        for (register int i = 0; i < k; ++i) {
            flag = false;
            find(len);
            if (!flag) break;
        }
        if (flag) {
            printf("%d %d", k, len);
            return 0;
        }
        
    }
    printf("%d %d", 1, sum);
    return 0;
}
