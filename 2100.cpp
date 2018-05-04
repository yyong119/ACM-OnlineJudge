#include <algorithm>
#include <cstdio>
const int MAXN = 50010;
int a[MAXN];

void HeapAdjust(int i , int size) {

    for (;i <= (size >> 1);) {
        int L = i << 1, R = i << 1 | 1, maxIndex = i;
        if (a[maxIndex] > a[L] && L <= size) maxIndex = L;
        if (a[maxIndex] > a[R] && R <= size) maxIndex = R;
        if (maxIndex != i) std::swap(a[i], a[maxIndex]);
        else break;
        i = maxIndex;
    }
}

int main() {

    int size; scanf("%d", &size);
    for (int i = 1; i <= size; ++i) scanf("%d", &a[i]);

    for (int i = (size >> 1); i > 0; --i) HeapAdjust(i, size);

    int tmp = size, temp = 0; long long ans = 0;
    for (int i = 1; i < size; ++i) {

        temp = a[1];
        a[1] = a[tmp--];
        HeapAdjust (1, tmp);
        a[1] += temp;
        ans += a[1];
        HeapAdjust (1, tmp);

    }
    printf("%lld\n", ans);
    return 0;
}
