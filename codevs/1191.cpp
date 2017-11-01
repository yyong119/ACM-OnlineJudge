#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define read(a) a=getint()
#define print(a) printf("%d", a)
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }

#define lc x<<1
#define rc x<<1|1
#define MID (l+r)>>1
#define lson l, m, lc
#define rson m+1, r, rc
const int N=200005;
int s[N*10], L, R, n;
bool add[N*10];
inline void pushup(const int &x) { s[x]=s[lc]+s[rc]; }
inline void pushdown(const int &x) {
  if(add[x]) {
    s[lc]=0; s[rc]=0;
    add[lc]=1; add[rc]=1;
    add[x]=0;
  }
}
void build(const int &l, const int &r, const int &x) {
  if(l==r) { s[x]=1; return; }
  int m=MID;
  build(lson); build(rson);
  pushup(x);
}
void update(const int &l, const int &r, const int &x) {
  if(L<=l && r<=R) { add[x]=1; s[x]=0; return; }
  pushdown(x);
  int m=MID;
  if(L<=m) update(lson); if(m<R) update(rson);
  pushup(x);
}
int query(const int &l, const int &r, const int &x) {
  if(L<=l && r<=R) return s[x];
  pushdown(x);
  int m=MID, ret=0;
  if(L<=m) ret+=query(lson); if(m<R) ret+=query(rson);
  pushup(x);
  return ret;
}
int main() {
  read(n);
  int m=getint();
  build(1, n, 1);
  while(m--) {
    read(L); read(R);
    update(1, n, 1);
    L=1, R=n;
    printf("%d\n", query(1, n, 1));
  }	
  return 0;
}