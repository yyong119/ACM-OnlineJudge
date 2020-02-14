#include <queue>
#include <cstdio>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long> > q;
int n;
long long ans, a, b, x;
inline long long read() {
    char ch = getchar(); long long res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i) {
        x = read(); q.push(x);
    }
    for (register int i = 1; i < n; ++i) {
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        ans += a + b;
        q.push(a + b);
    }
    printf("%lld", ans);
    return 0;
}
