#include <cstdio>
using namespace std;
#define MAX_AN 4000100
#define ZERO 2000005

int a[MAX_AN];
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
        a[tmp + ZERO] = 1;
    }
 
    scanf("%d", &p);
    while (p--) {
        int op, num;
        // scanf("%d%d", &op, &num);
        op = read(); num = read();
        a[num + ZERO] = op;
    }
 
    for (int i = 0; i < MAX_AN; ++i)
        if (a[i])
            printf("%d ", i - ZERO);
    return 0;
}