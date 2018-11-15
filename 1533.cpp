#include <cstdio>
using namespace std;

int steps(int n, int x, int y) {
    if (x == 1) return y;
    if (y == n) return x + n - 1;
    if (x == n) return 3 * n - y - 1;
    if (y == 1) return 4 * n - x - 2;
    return 4 * n - 4 + steps(n - 2, x - 1, y - 1);
}

int main() {

    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int ans = steps(n, x, y) - 1;
    printf("%d\n", ans);

    return 0;
}