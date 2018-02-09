/*
ID: forusac5
PROG: agrinet
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
const int MAXN = 100;
int N, cost[MAXN][MAXN], dist[MAXN];
bool vis[MAXN];
int main()
{
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", cost[i] + j);
        }
    }
    int ret = 0;
    MMset(dist, 0x7f);
    dist[0] = 0;
    for (int i = 0; i < N; i++) {
        int loc = -1;
        for (int j = 0; j < N; j++) {
            if (!vis[j]) {
                if (loc == -1 || dist[loc] > dist[j]) {
                    loc = j;
                }
            }
        }
        ret += dist[loc];
        vis[loc] = 1;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && dist[j] > cost[loc][j]) {
                dist[j] = cost[loc][j];
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}
