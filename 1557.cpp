#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 50000;
struct cow {
    int x, h;
} c[MAX_N + 5];

bool leftCrowded[MAX_N + 5], rightCrowded[MAX_N + 5];
int q[MAX_N + 5];
int head, tail, ans, n, d;

bool cmp(const cow & c1, const cow & c2) {
    return c1.x < c2.x;
}

int main() {

    ios::sync_with_stdio(false);

    cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> c[i].x >> c[i].h;

    sort(c, c + n, cmp);// make x in ascending order
    for (int i = 1; i < n; ++i) {
        int nearestPos = c[i].x - d;
        while (head <= tail && c[q[head]].x < nearestPos) head++;
        while (head <= tail && c[q[tail]].h <= c[i].h) tail--;
        if (head > tail) q[head] = i;
        if (c[q[head]].h >= c[i].h << 1) leftCrowded[i] = true;
        q[++tail] = i;
    }

    head = tail = 0;
    q[0] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        int nearestPos = c[i].x + d;
        while (head <= tail && c[q[head]].x > nearestPos) head++;
        while (head <= tail && c[q[tail]].h <= c[i].h) tail--;
        if (head > tail) q[head] = i;
        if (c[q[head]].h >= c[i].h << 1) rightCrowded[i] = true;
        q[++tail] = i;
    }

    for (int i = 0; i < n; ++i)
        ans += leftCrowded[i] && rightCrowded[i];
    cout << ans << endl;

    return 0;
}