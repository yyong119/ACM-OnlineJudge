#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAX_N 55
#define MAX_K 205
#define MAX_VALUE 2000005
using namespace std;
queue<int> q;
bool d[MAX_VALUE];
int val[MAX_N];
int n, k;

inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = res * 10 + ch - '0', ch = getchar();
    return res;
}

int main() {
    k = read(); n = read();
    for (int i = 0; i < n; ++i) val[i] = read();
    q.push(0);
    for (int i = 1; i <= k; ++i) {
        int cnt = q.size();
        for (int x = 0; x < cnt; ++x) {
            int v = q.front(); q.pop();
            for (int j = 0; j < n; ++j) {
                int v_tmp = v + val[j];
                if (!d[v_tmp]) {
                    q.push(v_tmp);
                    d[v_tmp] = true;
                }
            }
        }
    }
    for (int i = 1; i < MAX_VALUE; ++i)
        if (!d[i]) {
            printf("%d\n", i - 1);
            break;
        }
    return 0;
}
