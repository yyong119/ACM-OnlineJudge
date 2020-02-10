#include <cstdio>
#define MAX_N 200010
using namespace std;
int N, result;
int list[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
main(){
    N = read();
    for(register int i = 0; i < N; ++i) list[i] = read();
    for(register int i = 1; i < N; ++i)
        if (list[i] >= list[i - 1]) ++result;
    printf("%d\n", result);
    return 0;
}
