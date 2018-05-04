#include <cstdio>
#include <algorithm>
#include <cstdint>
using namespace std;



int a[50001], b[50001];
int ba=0, ea=0, bb=0, eb=0, n, ans=0;

inline int get_val(int * a, int & begin, int & end, const int & delta) {
    // delta is 0 or 1;
    if (begin + delta >= end) return INT32_MAX;
    return a[begin + delta];
}

inline void merge_once() {
    if (get_val(a, ba, ea, 0) > get_val(b, bb, eb, 0)) {
        if (get_val(a, ba, ea, 0) <  get_val(b, bb, eb, 1)) {
            b[eb++] = a[ba] + b[bb];
            ++ba;
            ++bb;
        } else {
            b[eb++] = b[bb] + b[bb + 1];
            ++bb;
            ++bb;
        }
    } else {
        if (get_val(a, ba, ea, 1) < get_val(b, bb, eb, 0)) {
            b[eb++] = a[ba] + a[ba + 1];
            ++ba;
            ++ba;
        } else {
            b[eb++] = a[ba] + b[bb];
            ++ba;
            ++bb;
        }
    }
    ans += b[eb - 1];
}

int main() {
   scanf("%d", &n);
   for (int i = 0; i < n; ++i) scanf("%d", a + i);
   ea = n;
   sort(a, a + ea);
   for (int j = 0; j < n - 1; ++j) merge_once();
   printf("%d\n", ans);
}
