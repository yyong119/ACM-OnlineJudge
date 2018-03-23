#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define GET (ch>='0'&&ch<='9')
using namespace std;

const int MAXN = 3000010;
int n, k, ans, h1, t1, h2, t2;
int a[MAXN], q1[MAXN],q2[MAXN];
 
void in(int &x) {
    char ch = getchar();
    x = 0;
    while (!GET) ch = getchar();
    while (GET) x = x * 10 + ch - '0', ch = getchar();
}
 
int main() {
 
    in(k);in(n);
    int tmp=1;
    for (int i = 1; i <= n; ++i) {
        in(a[i]);
        while (h1 != t1 && a[i] >= a[q1[t1 - 1]]) --t1;
        while (h2 != t2 && a[i] <= a[q2[t2 - 1]]) --t2;
        q1[t1++] = i; q2[t2++] = i;
        while (a[q1[h1]] - a[q2[h2]] > k)
            if (q1[h1] < q2[h2]) tmp = q1[h1] + 1, ++h1;
            else tmp = q2[h2] + 1, ++h2;
        ans = max(ans, i - tmp + 1);
    }
    printf("%d\n", ans);
}