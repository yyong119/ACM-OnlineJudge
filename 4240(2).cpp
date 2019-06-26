#include <cstdio>
using namespace std;
#define MAX_AN 4000100
#define MAX_N 2000010
#define ZERO 2000005
 
// int a[MAX_AN];
int a[MAX_N], b[MAX_N];
int s, p, tmp;
 
inline int read() {
    int p, data = 0;
    char ch = 0;
    while ((ch != '-') && ch < '0' || ch > '9') ch = getchar();
    if (ch=='-') {
        p = -1;
        ch = getchar();
    } else p = 1;
    while (ch >= '0' && ch <= '9') data = data * 10 + ch - '0', ch = getchar();
    return data * p;
}
 
int main() {
 
    scanf("%d", &s);
    for (int i = 0; i < s; ++i) {
        // scanf("%d", &tmp);
        tmp = read();
        if (tmp < 0)
            b[-tmp] = 1;
        else
            a[tmp] = 1;
    }
 
    scanf("%d", &p);
    while (p--) {
        int op, num;
        // scanf("%d%d", &op, &num);
        op = read(); num = read();
        if (num < 0)
            b[-num] = op;
        else
            a[num] = op;
    }
 
    for (int i = MAX_N - 1; i > 0; --i)
        if (b[i])
            printf("%d ", -i);
    for (int i = 0; i < MAX_N; ++i)
        if (a[i])
            printf("%d ", i);
    return 0;
}