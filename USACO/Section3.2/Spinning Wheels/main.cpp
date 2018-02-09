/*
ID: forusac5
PROG: spin
LANG: C++
*/
#include <cstdio>
#include <utility>
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

struct Wheel{
    int speed, num;
    vector <pair<int, int> > info;
    void input() {
        scanf("%d%d", &speed, &num);
        for (int i = 0; i < num; i++) {
            int start, val;
            scanf("%d%d", &start, &val);
            info.push_back(make_pair(start, val));
        }
    }
    void colour(int now, int arr[]) {
        int offset = (now * speed) % 360;
        for (int i = 0; i < num; i++) {
            for (int j = 0; j <= info[i].second; j++) {
                arr[(info[i].first + j + offset) % 360]++;
            }
        }
    }
} wheel[5];
int main()
{
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    int tot[360];
    for (int i = 0; i < 5; i++) {
        wheel[i].input();
    }
    for (int i = 0; i < 360; i++) {
        MMset(tot, 0);
        for (int j = 0; j < 5; j++) {
            wheel[j].colour(i, tot);
        }
        for (int j = 0; j < 360; j++) {
            if (tot[j] == 5)    {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    puts("none");
    return 0;
}
