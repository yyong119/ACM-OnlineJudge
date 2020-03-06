#include <iostream>
#include <cstring>
#define MAX_LEN 100010
#define min(x, y) ((x) < (y) ? (x) : (y))
using namespace std;
char str[MAX_LEN], ch;
int prev_low[MAX_LEN], fol_up[MAX_LEN];
int ans, n;
int main() {
    // input
    ios::sync_with_stdio(false);
    cin >> str;
    n = strlen(str);
    // init
    for (register int i = 1; i <= n; ++i)
        prev_low[i] = prev_low[i - 1] + (str[i - 1] >= 'a');
    for (register int i = n - 1; i >= 0; --i)
        fol_up[i] = fol_up[i + 1] + (str[i] < 'a');
    // find minimun
    ans = 0x7fffffff;
    for (register int i = 0; i <= n; ++i)
        ans = min(ans, prev_low[i] + fol_up[i]);
    cout << ans << "\n";
    return 0;
}
