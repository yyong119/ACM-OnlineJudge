#include <cstdio>
#define MAX_N 100010
using namespace std;
const double error = 1e-7;
int n, k;
double a[MAX_N];
bool check(double step_length) {
    double start_pos = a[0];
    int cnt = 1;
    for (register int i = 1; i < n; ++i) {
        if (a[i] - start_pos <= step_length) continue;
        if ((++cnt) > k) return false;
        start_pos = a[i];
    }
    return true;
}
int main() {
    scanf("%d%d", &n, &k);
    for (register int i = 0; i < n; ++i) scanf("%lf", &a[i]);
    double l = 0, r = a[n - 1] - a[0];
    while (r - l > error) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%.6lf", r / 2);
    return 0;
}
