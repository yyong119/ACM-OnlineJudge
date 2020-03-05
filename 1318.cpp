#include<iostream>
using namespace std;

int dp[50][10000];
int main()
{
    int N; cin >> N;
    int sum = (1 + N) * N / 2;
    if(sum % 2 != 0) {cout << 0 << endl; return 0;}
    dp[1][1] = 1;
    sum /= 2;
    for(int i = 2; i <= N; ++i)
    {
        for(int j = 1; j <= i * (i+1) / 2; ++j)
            dp[i][j] = dp[i-1][j] + dp[i-1][j-i];
    }
    cout << dp[N][sum] << endl;
    return 0;
}