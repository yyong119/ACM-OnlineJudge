/*
ID: forusac5
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>
#include <map>
#include <cassert>
#define MMset(a,b) memset(a,b,sizeof(a))
using namespace std;
int K, N;
int dp[2000001];
int main()
{
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    scanf("%d%d", &K, &N);
    MMset(dp, 0x3f);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        for (int j = num; j <= 2000000; j++) {
            dp[j] = min(dp[j], dp[j - num] + 1);
        }
    }
    for (int i = 1; i <= 2000000; i++) {
        if (dp[i] > K) {
            printf("%d\n", i - 1);
            break;
        }
    }
    return 0;
}
