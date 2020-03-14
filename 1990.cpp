#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 2000010
using namespace std;
int n, m, cur_time;
int cd_seq[MAX_N], id_map[MAX_N], pos_map[MAX_N], time_seq[MAX_N];
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return res * flag;
}
inline void swap_element(int x, int y) {
    swap(cd_seq[x], cd_seq[y]);
    swap(id_map[x], id_map[y]);
    pos_map[id_map[x]] = x;
    pos_map[id_map[y]] = y;
}
inline bool cmp(const int &x, const int &y) {
    return (cd_seq[x] == cd_seq[y] ? time_seq[id_map[x]] > time_seq[id_map[y]] : cd_seq[x] < cd_seq[y]);
}
void push_down(int x) {
    for (register int k = x; (k << 1) <= n;) {
        int min_id = k, l = k << 1, r = k << 1 | 1;
        // left child
        if (cmp(l, min_id)) min_id = l;
        // right child
        if (r <= n && cmp(r, min_id)) min_id = r;
        // check to push down
        if (min_id == k) return;
        swap_element(k, min_id);
        k = min_id;
    }
}
void push_up(int x) {
    for (register int k = x; k > 1;) {
        // parent
        int p = k >> 1;
        // chekc to push up
        if (cmp(k, p)) {
            swap_element(k, p);
            k = p;
        }
        else return;
    }
}
int main() {
    n = read(), m = read();
    for (register int i = 1; i <= n; ++i) {
        cd_seq[i] = read();
        id_map[i] = pos_map[i] = i;
        time_seq[i] = ++cur_time;
    }
    for (register int i = (n >> 1); i > 0; --i)
        push_down(i);
    for (register int i = 0; i < m; ++i) {
        int x = read(), diff = read();
        time_seq[x] = ++cur_time;
        if (diff == 1) {
            ++cd_seq[pos_map[x]];
            push_down(pos_map[x]);
        }
        else {
            --cd_seq[pos_map[x]];
            push_up(pos_map[x]);
        }
        printf("%d\n", id_map[1]);
    }
    return 0;
}