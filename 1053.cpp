#include <cstdio>
#include <algorithm>
 
using namespace std;
 
const int MAXN = 100001;
struct Point {
    int x, y, z;
}points[MAXN];
int n;
int curx[MAXN], cury[MAXN];
 
bool comp(const Point& a, const Point& b){
 
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
 
int find(int x,int y){
 
    Point tofind;
    tofind.x = x; tofind.y = y;
    Point* f = lower_bound(points, points+n, tofind, comp);
    if((f != points+n) && (f->x == x) && (f->y == y)) return f->z;
    return 0;
}
 
int main() {
    int m, op, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].z);
    for (int i = 0; i < MAXN; ++i) curx[i] = i;
    for (int i = 0; i < MAXN; ++i) cury[i] = i;
    scanf("%d", &m);
    sort(points, points + n, comp);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &op, &x, &y);
        if(op == 0) {
            swap(curx[x], curx[y]);
        } else if(op == 1)
            swap(cury[x], cury[y]);
        else{
            printf("%d\n", find(curx[x], cury[y]));
        }
    }
    return 0;
}