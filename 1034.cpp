#include <iostream>
#include <cstdio>
using namespace std;
int n, k, i, maxnum, minnum, mid, countn;
int a[200001];
bool flag;
int main() {
    scanf("%d%d", &n, &k);
    minnum = 1000000001;
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
        maxnum = max(maxnum, a[i]);
        minnum = min(minnum, a[i]);
    }
    while (minnum < maxnum) {
        mid = (minnum + maxnum) / 2;
        countn = 0; flag = false;
        for (i = 1; i <= 2*n; i++) {
            if (countn == k) { flag = true; break; }
            if (a[i] <= mid) countn++; else countn = 0;
        }
        if (flag) maxnum = mid; else minnum = mid + 1;
    }
    printf("%d\n", (minnum + maxnum) / 2);
    return 0;
}