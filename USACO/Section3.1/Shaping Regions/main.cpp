/*
ID: forusac5
PROG: rect1
LANG: C++
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <cassert>
#define MMset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int MAXN = 1010;
const int MAXS = 4 * 10100;
int A, B, N;
vector <int> S;
struct Point {
    int llx, lly, urx, ury, color;
    void input() {
        scanf("%d%d%d%d%d", &llx, &lly, &urx, &ury, &color);
        ury--;
        S.push_back(llx);
        S.push_back(urx);
    }
} point[MAXN];
int pos[10001], cnt[2501], tot[2501];
int segl[MAXS], segr[MAXS], segm[MAXS], cover[MAXS];

void buildSeg(int l, int r, int idx) {

    segl[idx] = l;
    segr[idx] = r;
    segm[idx] = (l + r) >> 1;
    cover[idx] = 1;
    if (l == r) return;
    else {
        int mid = (l + r) / 2;
        buildSeg(l, mid, 2 * idx);
        buildSeg(mid + 1, r, 2 * idx + 1);
    }
}

void insertSeg(int l, int r, int col, int idx) {
    if (l <= segl[idx] && segr[idx] <= r) {
        cover[idx] = col;
        return;
    }
    if (cover[idx] != -1) {
        cover[2 * idx + 1] = cover[2 * idx] = cover[idx];
    }
    cover[idx] = -1;
    if (l <= segm[idx]) {
        insertSeg(l, r, col ,2 * idx);
    }
    if (r > segm[idx]) {
        insertSeg(l, r, col, 2 * idx + 1);
    }
}

void calcSeg(int idx) {
    if (cover[idx] != -1) {
        cnt[cover[idx]] += (segr[idx] - segl[idx] + 1);
        return;
    }
    if (segr[idx] == segl[idx]) return;
    calcSeg(2 * idx);
    calcSeg(2 * idx + 1);
}

int main()
{

    freopen("rect1.in", "r", stdin);
    freopen("rect1.out", "w", stdout);
    scanf("%d%d%d", &A, &B, &N);
    S.clear();
    for (int i = 0; i < N; i++) {
        point[i].input();
    }
    S.push_back(A);
    S.push_back(0);
    sort(S.begin(), S.end());
    int len = unique(S.begin(), S.end()) - S.begin();

    for (int i = 0; i < N; i++) {
        point[i].llx = lower_bound(S.begin(), S.begin() + len, point[i].llx) - S.begin();
        point[i].urx = lower_bound(S.begin(), S.begin() + len, point[i].urx) - S.begin();
    }

    for (int i = 0; i + 1< len; i++) {
        buildSeg(0, B - 1 , 1);
        MMset(cnt, 0);
        for (int j = 0; j < N; j++) {
            if (point[j].llx <= i && i + 1 <= point[j].urx) {
                insertSeg(point[j].lly, point[j].ury, point[j].color, 1);
            }
        }
        calcSeg(1);
        for (int j = 0; j <= 2500; j++) {
            tot[j] += cnt[j] * (S[i + 1] - S[i]);
        }
    }
    for (int i = 0; i <= 2500; i++) {
        if (tot[i]) {
            printf("%d %d\n", i, tot[i]);
        }
    }
    return 0;
}
