#include <cstdio>
#include <stack>
#define MAX_N 10000010
using namespace std;
int n, tmp;
// int v[MAX_N];
stack<int> v_non_inc;
inline int read() {
    char ch = getchar(); int res = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res;
}
int main() {
    n = read();
    // for (register int i = 0; i < n; ++i)
    //     v[read()] = read();
    for (register int i = 0; i < n; ++i) {
        read(); tmp = read();
        while (!v_non_inc.empty() && v_non_inc.top() > tmp)
            v_non_inc.pop();
        v_non_inc.push(tmp);
    }
    // int ans = 0, v_last = 0x7fffffff;
    // for (register int i = MAX_N - 1; i >= 0; --i) {
    //     if (!v[i]) continue;
    //     if (v[i] <= v_last) {
    //         ++ans;
    //         v_last = v[i];
    //     }
    // }
    // printf("%d", ans);
    printf("%d", v_non_inc.size());
    return 0;
}
