/*
ID: forusac5
PROG: kimbits
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
int N, L;
long long I;
int dp[32][32], sum[32][32];
char ret[40];

int main()
{
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    dp[0][0] = 1, sum[0][0] = sum[0][1]= 1;
    dp[1][0] = 1, dp[1][1] = 1;
    sum[1][0] = 1, sum[1][1] = 2;
    for (int j = 2; j <= 31; j++) {
        sum[0][j] = 1;
        sum[1][j] = sum[1][j - 1] + dp[1][j];
    }
    for (int i = 2; i <= 31; i++) {
        dp[i][0] = sum[i][0] = 1;
        for (int j = 1; j <= 31; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            sum[i][j] = sum[i][j - 1] + dp[i][j];
        }
    }
    cin >> N >> L >> I;
    long long remainL = L;
    for (int i = 0; i < N; i++) {
        int nextP = N - i - 1;
        if (I > sum[nextP][remainL]) {
            printf("1");
            I -= sum[nextP][remainL];
            remainL--;
        } else {
            if (nextP == 0 && I == 1 && remainL == 1)   printf("1");
            else                       printf("0");
        }
    }
    printf("\n");
    return 0;
}
