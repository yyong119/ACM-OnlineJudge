#include <cstdio>
 
using namespace std;
 
const int MAXN = 300000;
int a[MAXN + 10];
long num;
 
void mergearr(int l, int r) {
 
    int mid = (l + r) >> 1, i = l, j = mid + 1, k = l;
    int temp[MAXN + 10];
    while ((i <= mid)&&(j <= r)) {
        if (a[i] > a[j]) {
            temp[k++] = a[j++];
            num += mid - i + 1;
        } else {
            temp[k++] = a[i++];
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int i = l; i <= r; i++) a[i] = temp[i];
}
 
void merge_sort(int l, int r) {
 
    if (l < r) {
        int mid = (l + r) >> 1;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        mergearr(l, r);
    }
}
 
int main() {
 
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    merge_sort(1, n);
    printf("%ld\n", num);
}