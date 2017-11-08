#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAXN 50
int d[ MAXN + 10 ];
bool edge[ MAXN + 10 ][ MAXN + 10 ];
double p[ MAXN + 10 ][ MAXN + 10 ], f[2][ MAXN + 10 ][ MAXN + 10 ];
int N, M, T, now, bef;

int main()
{
    int u, v;
    scanf("%d %d %d", &N, &M, &T);
    while (M--)
    {
        scanf("%d %d", &u, &v);
        edge[u][v] = true, d[u]++;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (edge[i][j])
            {
                if (edge[j][i]) p[i][j] = 1 / (double (d[j]));
                    else p[i][j] = 1 / (double (d[j] + 1));
            }
    now = 0;
    f[now][0][1] = 100;
    edge[0][1] = true;
    p[0][1] = 1 / (double (d[1] + 1));
    for (int i = 1; i <= T; i++)
    {
        bef = now, now ^= 1;
        memset(f[now], 0, sizeof(f[now]));
        for (int j = 0; j <= N; j++)
            for (int k = 0; k <= N; k++)
                if (edge[j][k])
                {
                    f[now][j][k] = f[bef][j][k] * p[j][k];
                    for (int t = 0; t <= N; t++)
                        if (t != k && edge[t][j])
                            f[now][j][k] += f[bef][t][j] * p[t][j];
                }
    }
    double ans;
    for (int i = 1; i <= N; i++)
    {
        ans = 0;
        for (int j = 0; j <= N; j++)
            ans += f[now][j][i];
        printf("%.3f\n", ans);
    }
    return 0;
}