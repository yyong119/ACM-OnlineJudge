#include <cstdio>
using namespace std;
const int MAX_N = 100005;
int n;
int nums[MAX_N], smaller[MAX_N], pos[MAX_N], result[MAX_N];

void mergesort(int *nums, int *smaller, int *pos, int l, int r) {

    if (l >= r) return;
    int mid = (l + r) >> 1;
    mergesort(nums, smaller, pos, l, mid);
    mergesort(nums, smaller, pos, mid + 1, r);
    int merged[r - l + 1];
    int i = l, j = mid + 1, k = 0, step = 0;
    while (i <= mid || j <= r) {
        if (i > mid) {
            ++step;
            merged[k++] = pos[j++];
        } else if (j > r) {
            smaller[pos[i]] += step;
            merged[k++] = pos[i++];
        } else if (nums[pos[i]] <= nums[pos[j]]) {
            smaller[pos[i]] += step;
            merged[k++] = pos[i++];
        } else {
            ++step;
            merged[k++] = pos[j++];
        }
    }
    for (int i = 0; i < r - l + 1; ++i) pos[l + i] = merged[i];
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);
    for (int i = 0; i < n; ++i) pos[i] = i;
    mergesort(nums, smaller, pos, 0, n - 1);
    for (int i = 0; i < n; ++i) printf("%d ", smaller[i]);
    return 0;
}
