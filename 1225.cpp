#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
int main() {
    int n; int a[1000050];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    int cnt = 1;
    for (int i = 1; i < n; ++i)
        if (a[i] != a[i - 1]) ++cnt;
    printf("%d\n", cnt);
    return 0;
}
