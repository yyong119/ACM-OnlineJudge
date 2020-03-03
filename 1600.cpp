#include <cstdio>
using namespace std;
char ch;
int k;
int main() {
    ch = getchar();
    while (ch >= '0' && ch <= '9') {
        if (ch > k) k = ch;
        ch = getchar();
    }
    printf("%d", k ^ 48);
    return 0;
}
