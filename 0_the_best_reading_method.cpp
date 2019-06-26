#include <cstdio>
using namespace std;

int a, b;

inline int read() {
    
    int p, data = 0;
    char ch = 0;
    while ((ch != '-') && ch < '0' || ch > '9')
        ch = getchar();
    if (ch=='-') {
        p = -1;
        ch = getchar();
    }
    else
        p = 1;
    while (ch >= '0' && ch <= '9')
        data = data * 10 + ch - '0', ch = getchar();
    return data * p;
}

int main() {

    a = read();
    b = read();
    printf("%d\n", a + b);
    return 0;
}