#include<stdio.h>  
#include<string.h>  
#define INF 0xffffff  
int main()  
{  
    int n, num[111], sum[111] = {0}, min;  
    int dp[111][111];  
    memset(dp, 0, sizeof(dp));   
    scanf("%d", &n);  
    for(int i = 1; i <= n; i++)  
    {  
        scanf("%d", &num[i]);  
        sum[i] = sum[i - 1] + num[i];  
    }  
    for(int len = 2; len <= n; len++)  
    {  
        for(int i = 1; i <= n - len + 1; i++)  
        {  
            int j = i + len - 1;  
            min = INF;  
            for(int k = i; k < j; k++)  
            {  
                if(dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1] < min)  
                    min = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];  
            }  
            dp[i][j] = min;  
        }  
    }  
    printf("%d\n", dp[1][n]);  
    return 0;  
}  