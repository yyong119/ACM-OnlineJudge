#include <iostream>
using namespace std;

int height[1001];
int leftH[1001];

int main() {
    int n;
    cin >> n;
    char eat;
    for (int i = 1; i <= n; ++i) {
        cin >> eat >> height[i];
        leftH[i] = (leftH[i - 1] < height[i] ? height[i] : leftH[i - 1]);
    }
    int rightH = height[n];
    int ans = 0;
    for (int i = n - 1; i >= 1; --i) {
        int min = (leftH[i - 1] < rightH ? leftH[i - 1] : rightH);
        if (height[i] < min) ans += min - height[i];
        else rightH = height[i];
    }
    cout << ans << endl;
    return 0;
}