#include <iostream>
using namespace std;
long long n;
long long num(long long x) {
    if (x < 3) return x;
    long long r = x / 3, m = x - r - (r << 1);
    return (m + 1) * num(r) + m;
}
int main() {
    cin >> n;
    cout << n - num(n);
    return 0;
}