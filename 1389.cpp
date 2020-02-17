#include <cstdio>
#include <cstring>
#define MAX_Y 500010
#define N 9
#define min(x, y) ((x) < (y) ? (x) : (y))
using namespace std;
const int price[N] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int y;
int f[MAX_Y];
int main() {
    scanf("%d", &y);
    memset(f, 0x3f3f3f3f, sizeof(f));
    f[0] = 0;
    for (register int i = 0; i < N; ++i)
        for (register int j = price[i]; j < MAX_Y; ++j)
            if (f[j - price[i]] < 0x3f3f3f3f)
                f[j] = min(f[j], f[j - price[i]] + 1);
    // for (register int i = 1; i < 25; ++i)
    //     printf("%d: %d\n", i, f[i]);
    int cur_min = 0x7fffffff;
    for (register int i = y; i < MAX_Y; ++i)
            cur_min = min(cur_min, f[i] + f[i - y]);
    printf("%d", cur_min);
    return 0;
}
