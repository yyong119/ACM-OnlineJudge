/*
ID: forusac5
PROG: fact4
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

int main()
{
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);
    int N;
    scanf("%d", &N);
    long long ret = 1;
    for (int i = 1; i <= N; i++) {
        ret *= i;
        while (ret % 10 == 0) {
            ret /= 10;
        }
        ret = ret % 1000000;
    }
    printf("%d\n", (int)(ret % 10));
    return 0;
}
