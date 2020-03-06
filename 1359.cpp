#include <cstdio>
using namespace std;
char ch;
int ans, cnt;
int main() {
    ch = getchar();
    while (ch != '\n') {
        ++cnt;
        if (ch >= 'A' && ch <= 'Z')
            ans += cnt * (ch - 'A' + 1);
        else if (ch >= 'a' && ch <= 'z')
            ans += cnt * (ch - 'a' + 27);
        ch = getchar();
    }
    printf("%d", ans);
    return 0;
}
