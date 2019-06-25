#include <cstdio>
#include <algorithm>
#define MAX_A 165
#define MAX_B 45
using namespace std;
int f[MAX_A][MAX_B];

int main() {
    int case_num;
    scanf("%d", &case_num);
    f[0][0] = 1;
    for (int i = 0; i < MAX_A; ++i)
        f[i][1] = 1;
    for (int i = 1; i < MAX_A; ++i)
        for (int j = 1; j <= min(i, MAX_B - 1); ++j)
            f[i][j] = f[i - 1][j - 1] + f[i - j][j];
    int a, b;
    while(case_num--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", f[a][b] >> 1);
    }
    return 0;
}