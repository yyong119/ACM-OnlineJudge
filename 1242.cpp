#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX_N 10010
using namespace std;
int a, b, ans;
bool pr[MAX_N];
int main() {
    scanf("%d%d", &a, &b);
    pr[1] = true;
    for (register int i = 2; i <= sqrt(b); ++i)
        if (!pr[i])
            for (register int j = 2; i * j <= b; ++j) pr[i * j] = true;
    for(register int i = a; i <= b; ++i)
        if (!pr[i]) ++ans;
    printf("%d\n", ans);
    return 0;
}