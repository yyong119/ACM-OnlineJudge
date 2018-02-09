/*
ID: forusac5
PROG: ratios
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
struct ANS {
    int i, j, k, l;
    ANS(int _i = 0, int _j = 0, int _k = 0, int _l = 0) {
        i = _i;
        j = _j;
        k = _k;
        l = _l;
    }
    void print() {
        if (i + j + k + l == 0) printf("NONE\n");
        else    printf("%d %d %d %d\n", i, j, k, l);
    }
} ans;
int num[3][3], goal[3];
int main()
{
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    int sumg = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d", goal + i);
        sumg += goal[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    int mins = 0x7fffffff;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                int a = i * num[0][0] + j * num[1][0] + k * num[2][0];
                int b = i * num[0][1] + j * num[1][1] + k * num[2][1];
                int c = i * num[0][2] + j * num[1][2] + k * num[2][2];
                int sumr = a + b + c;
                if (sumr != 0 && sumr % sumg == 0) {
                    int div = sumr / sumg;
                    if (div * goal[0] == a
                     && div * goal[1] == b
                     && div * goal[2] == c
                     && mins > sumr) {
                        mins = sumr;
                        ans = ANS(i, j, k, div);
                     }
                }
            }
        }
    }
    ans.print();
    return 0;
}
