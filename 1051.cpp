#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
const int MAXN = 10001;
 
int main() {
 
    int n, m;
    long times = 0;
    int a[MAXN];
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%d", &m);
    while (m) {
        scanf("%d", &a[0]);
        for (int i = 1; i <= n; ++i) {
            ++times;
            if (a[i] == a[0]) {
                for (int j = i; j >= 1; --j) a[j] = a[j - 1];
                break;
            }
        }
        --m;
    }
    printf("%d\n", times);
}