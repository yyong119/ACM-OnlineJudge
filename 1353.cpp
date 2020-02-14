#include <cstdio>
#define MAX_N 1000010
using namespace std;
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    // return res * flag;
    return res;
}
inline int f(int x) {
    if (x <= 100) return f(f(x + 11));
    else return x - 10;
}
int main() {
    // int n = 100;
    // for (int i = 0; i <= 100; ++i)
    //     printf("%d: %d\n", i, f(i));
    int tmp = read();
    while (tmp) {
        printf("%d\n", tmp > 100 ? tmp - 10 : 91);
        tmp = read();
    }
    return 0;
}