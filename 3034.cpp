#include <iostream>
#include <cstdio>
#include <cmath>
#define MAX_N 1000050
using namespace std;
int n, l, r;
// bool a[MAX_N];
bool isPrime(int n) {
	if (n == 2 || n == 3) return true;
	if (n % 6 != 1 && n % 6 != 5) return false;
	for (register int i = 5; i <= sqrt(n); i += 6)
	    if (!(n % i) | !(n % (i + 2))) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    l = r = n;
    while (!isPrime(l)) --l;
    while (!isPrime(r)) ++r;
    // for (register int i = 2; i < sqrt(MAX_N); ++i)
    //     if (!a[i])
    //         for (register int j = 2; i * j < MAX_N; ++j)
    //             a[i * j] = true;

    // l = r = n;
    // while (a[l]) --l;
    // while (a[r]) ++r;
    cout << r - l << '\n';
    return 0;
}
