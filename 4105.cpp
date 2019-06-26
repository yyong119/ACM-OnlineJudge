#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 200010

int a[MAX_N];
int n, m;

int binary_search(int x) {

    int l = 0, r = n - 1, mid;
    int delta = 0x7fffffff;
    while (l < r) {
        mid = (l + r) >> 1;
        if (x > a[mid])
            l = mid + 1;
        else if (x < a[mid])
            r = mid - 1;
        else
            return 0;
    }
    
    for (int i = max(0, mid - 3); i < min(n, mid + 3); ++i)
            delta = min(delta, abs(a[i] - x));
    return delta;
}

int main() {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    while(m--) {
        int x;
        scanf("%d", &x);
        int ans = binary_search(x);
        printf("%d\n", ans);
    }
    return 0;
}