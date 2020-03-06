#include <cstdio>
#define MAX_N 20
using namespace std;
int r, c;
int f[MAX_N][MAX_N];
char map[MAX_N][MAX_N];
inline int read_RB() {
    char ch = getchar();
    while (ch != 'R' && ch != 'B') ch = getchar();
    return ch;
}
int main() {
    scanf("%d %d", &r, &c);
    for (register int i = 0; i < r; ++i)
        for (register int j = 0; j < c; ++j)
            map[i][j] = read_RB();
    f[0][0] = 1;
    for (register int bx = 1; bx < r; ++bx)
        for (register int by = 1; by < c; ++by)
            for (register int ax = 0; ax < bx; ++ax)
                for (register int ay = 0; ay < by; ++ay)
                    if (map[ax][ay] != map[bx][by])
                        f[bx][by] += f[ax][ay];
    // for (register int i = 0; i < r; ++i) {
    //     for (register int j = 0; j < c; ++j)
    //         printf("%d ", f[i][j]);
    //     printf("\n");
    // }
    printf("%d", f[r - 1][c - 1]);
    return 0;
}
