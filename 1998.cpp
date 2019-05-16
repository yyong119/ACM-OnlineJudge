#include <cstdio>
#include <algorithm>
#define MAX_N 100010
using namespace std;
int a[MAX_N];
int cnt, n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < (n >> 1); ++i)
        cnt += a[n - 1 - i] - a[i];
    printf("%d\n", cnt);
    return 0;
}