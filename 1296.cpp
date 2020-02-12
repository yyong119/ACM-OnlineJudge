#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX_N 5050
#define MAX_LEN 1000
using namespace std;
struct LONG_INT {
    char num[MAX_LEN];
	LONG_INT() {
		num[0] = '0'; num[1] = '\0';
	}
	LONG_INT operator+(const LONG_INT& num2) {
		LONG_INT ans;
		int k = 0, cur, state = 0;
		for(int i = 0, j = 0; num[i] || num2.num[j];) {
			if (!num[i])
				cur = num2.num[j++] - '0' + state;
			else if (!num2.num[j])
				cur = num[i++] - '0' + state;
			else
				cur = num[i++] - '0' + num2.num[j++] - '0' + state;
			ans.num[k++] = cur % 10 + '0';
			state = cur / 10;
		}
		if(state) ans.num[k++] = '1';
		ans.num[k] = '\0';
		return ans;
	}
	void init(int a) {
		num[0] = '0' + a;
		num[1] = '\0';
	}
} cnt[MAX_N], total_cnt;
int n, ans;
int a[MAX_N], f[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
int main() {
    n = read();
    for (register int i = 0; i < n; ++i)
        a[i] = read();
    for (register int i = 0; i < n; ++i) {
        // calc longest sequence
        f[i] = 1;
        for (register int j = 0; j < i; ++j)
            if (a[j] > a[i]) f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
        // calc number of solutions
        if (f[i] == 1) {
            // set to 1
            cnt[i].init(1);
        }
        for (register int j = 0; j < i; ++j) {
            if (f[i] == f[j] && a[i] == a[j]) {
                // set to 0
                cnt[j].init(0);
            }
            if (f[i] == f[j] + 1 && a[i] < a[j])
                // set to sum of 2 number
                cnt[i] = cnt[i] + cnt[j];
        }
    }
    printf("%d ", ans);
    for (register int i = 0; i < n; ++i)
        if (f[i] == ans)
            total_cnt = total_cnt + cnt[i];
    for (register int i = strlen(total_cnt.num) - 1; i >= 0; --i)
        printf("%c", total_cnt.num[i]);
    return 0;
}