/*
ID: forusac5
PROG: inflate
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
int dp[10001];
int M, N;
int main()
{
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    scanf("%d %d\n", &M, &N);
    for (int i = 0; i < N; i++) {
        int val, cost;
        scanf("%d %d\n", &val, &cost);
        for (int j = cost; j <= M; j++) {
            dp[j] = max(dp[j], dp[j - cost] + val);
        }
    }
    int ret = 0;
    for (int i = 0; i <= M; i++) {
        ret = max(ret, dp[i]);
    }
    printf("%d\n", ret);
    return 0;
}
