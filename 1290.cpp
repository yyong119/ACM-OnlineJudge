#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX_N 300010
using namespace std;
int n, ans, heap_size;
long long T;
struct Node {
    long long x, t;
} a[MAX_N];
int gr_heap[MAX_N];
inline long long read() {
    char ch = getchar(); long long res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    // return res * flag;
    return res;
}
inline bool cmp(const Node &p, const Node &q) {
    return p.x < q.x;
}
int main() {
    n = read(); T = read();
    for (register int i = 1; i <= n; ++i)
        a[i].x = read(), a[i].t = read();
    sort(a + 1, a + n + 1, cmp);
    make_heap(gr_heap, gr_heap + heap_size, less<int>());
    for (register int i = 1; i <= n; ++i) {
        T -= a[i].x - a[i - 1].x;
        while (heap_size > 0 && T < 0) {
            T += gr_heap[0];
            pop_heap(gr_heap, gr_heap + heap_size--, less<int>());
        }
        if (T < 0) break;
        if (T >= a[i].t) {
            T -= a[i].t;
            gr_heap[heap_size++] = a[i].t;
            push_heap(gr_heap, gr_heap + heap_size, less<int>());
            ans = max(ans, heap_size);
        }
        else if (heap_size > 0 && a[i].t < gr_heap[0]) {
            T += gr_heap[0];
            pop_heap(gr_heap, gr_heap + heap_size, less<int>());
            T -= a[i].t;
            gr_heap[heap_size - 1] = a[i].t;
            push_heap(gr_heap, gr_heap + heap_size, less<int>());
        }
    }
    printf("%d", ans);
    return 0;
}
