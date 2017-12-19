#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

ifstream fin("numtri.in");
ofstream fout("numtri.out");

int a[1002][1002];
int dp[1002][1002];
int max(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    int R; fin >> R;
    for(int i = 1; i <= R; ++i)
        for(int j = 1; j <= i; ++j)
            fin >> a[i][j];
    //第一种方法从下往上浮
    /*
    for(int i = 1; i <= R; ++i) dp[R][i] = a[R][i];
    for(int i = R-1; i >= 1; --i)
    {
        for(int j = 1; j <= i; ++j)
        {
            dp[i][j] = a[i][j] + max(dp[i+1][j+1],dp[i+1][j]);
        }
    }
    fout << dp[1][1] << endl;
    */
    
    //第二种方法从上往下浮(更加直观的想法)
    dp[1][1] = a[1][1];
    int res = 0;
    for(int i = 2; i <= R; ++i)
    {
        dp[i][1] = dp[i-1][1] + a[i][1];
        dp[i][i] = dp[i-1][i-1] + a[i][i];
        for(int j = 2; j < i; ++j)
            dp[i][j] = a[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
    }
    for(int i = 1; i <= R; ++i)
    {
        if(dp[R][i] > res)
            res = dp[R][i];
    }
    fout << res << endl;
    
    return 0;
}