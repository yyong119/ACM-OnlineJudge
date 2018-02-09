/*
ID: forusac5
PROG: camelot
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
int dirx[] = {1, 2, -1, 2, 1, -2, -1, -2};
int diry[] = {2, 1, 2, -1, -2, 1, -2, -1};
struct Node{
    int x, y;
    Node(int _x = 0, int _y = 0):x(_x), y(_y){};
    int input() {
        char str[2];
        int ret = scanf("%s %d", str, &y);
        if (ret == EOF) return ret;
        x = str[0] - 'A';
        y--;
        return ret;
    }
} king, knight[900];
int dist[30][30][30][30];
int dist2[30][30][30][30];
bool inq[30][30];
int R, C;
std::deque<pair<int, int> >Q;

inline bool in(int i, int j) {
    return ( 0 <= i && i < R && 0 <= j && j < C);
}
void BFS(int si, int sj) {
    Q.clear();
    Q.push_back(make_pair(si, sj));
    dist[si][sj][si][sj] = 0;
    inq[si][sj] = 1;
    while (!Q.empty()) {
        int nx = Q.front().first;
        int ny = Q.front().second;
        inq[nx][ny] = 0;
        Q.pop_front();
        for (int i = 0; i < 8; i++) {
            int nnx = nx + dirx[i];
            int nny = ny + diry[i];
            if ( in(nnx, nny)
                && (dist[si][sj][nnx][nny] == -1
                    || dist[si][sj][nnx][nny] > dist[si][sj][nx][ny] + 1) ) {
                dist[si][sj][nnx][nny] = dist[si][sj][nx][ny] + 1;
                if (!inq[nnx][nny]) {
                    inq[nnx][nny] = 1;
                    Q.push_back(make_pair(nnx, nny));
                }
            }
        }
    }

}

int main() {
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);
    MMset(dist, -1);
    MMset(dist2, -1);
    scanf("%d%d", &R, &C);
    king.input();
    int num_knight = 0;
    while (knight[num_knight].input() != EOF) {
        num_knight++;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            MMset(inq, 0);
            BFS(i, j);
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            MMset(inq, 0);
            BFS2(i, j);
    }
}
