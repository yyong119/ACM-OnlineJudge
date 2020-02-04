#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX_C 100010
#define RG register
using namespace std;
struct Node {
    int grd, sch;
} a[MAX_C];
int n, c, f, half;
int sum_left[MAX_C], sum_right[MAX_C], max_heap[MAX_C];
inline int read() {
    char ch = getchar(); int flag = 1, res = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * flag;
}
inline bool cmp_grd(const Node& a, const Node& b) {
    return a.grd < b.grd;
}
inline bool cmp_sch(const Node& a, const Node& b) {
    return a.sch < b.sch;
}
int main() {
    n = read(); c = read(); f = read();
    half = n >> 1;// numbers that two side of center number need
    for (RG int i = 0; i < c; ++i)
        a[i].grd = read(), a[i].sch = read();
    sort(a, a + c, cmp_grd);
    // calc minimum sum of the left part
    for (RG int i = 0; i < half; ++i) {
        max_heap[i] = a[i].sch;
        sum_left[half - 1] += a[i].sch;
    }
    make_heap(max_heap, max_heap + half, less<int>());
    for (RG int i = half; i < c; ++i) {
        sum_left[i] = sum_left[i - 1];
        if (a[i].sch < max_heap[0]) {
            sum_left[i] -= max_heap[0];
            sum_left[i] += a[i].sch;
            pop_heap(max_heap, max_heap + half, less<int>());
            max_heap[half - 1] = a[i].sch;
            push_heap(max_heap, max_heap + half, less<int>());
        }
    }
    // calc minimum sum of the right part
    for (RG int i = c - 1; i >= c - half; --i) {
        max_heap[c - i - 1] = a[i].sch;
        sum_right[c - half] += a[i].sch;
    }
    make_heap(max_heap, max_heap + half, less<int>());
    for (RG int i = c - half - 1; i >= 0; --i) {
        sum_right[i] = sum_right[i + 1];
        if (a[i].sch < max_heap[0]) {
            sum_right[i] -= max_heap[0];
            sum_right[i] += a[i].sch;
            pop_heap(max_heap, max_heap + half, less<int>());
            max_heap[half - 1] = a[i].sch;
            push_heap(max_heap, max_heap + half, less<int>());
        }
    }
    // enumerate each center number
    for (RG int i = c - half - 1; i >= half; --i)
        if (sum_left[i - 1] + sum_right[i + 1] + a[i].sch <= f) {
            printf("%d\n", a[i].grd);
            return 0;
        }
    printf("-1\n");
    return 0;
}
