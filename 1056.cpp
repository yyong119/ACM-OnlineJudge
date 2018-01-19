#include <cstdio>

int N, M, x, y, rt1, rt2, rt, size, cnt;
int treeArr[500001], father[500001];
char op;

void add(int x, int y) {
    for (int i = x; i <= N; i += i&(-i))
        treeArr[i] += y;
}

int query(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= i&(-i))
        sum += treeArr[i];
    return sum;
}

int find(int x) {
    if (father[x] < 0) return x;
    else if (father[x] == 0) return 0;
    else return father[x] = find(father[x]);
}

void merge(int root1, int root2) {
    if (root1 == root2) return;
    add(-father[root1], -1);
    add(-father[root2], -1);
    if (father[root1] > father[root2]) {
        father[root2] += father[root1];
        father[root1] = root2;
        add(-father[root2], 1);
    }
    else {
        father[root1] += father[root2];
        father[root2] = root1;
        add(-father[root1], 1);
    }
    --cnt;
}

int findK(int k) {
    if (cnt < k) return 0;
    k = cnt - k + 1;
    int l = 1, r = N;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (query(mid) < k) l = mid + 1; else r = mid - 1;
    }
    return l;
}

void eat(int root) {
    if(father[root]) {
        add(-father[root], -1);
        father[root] = 0;
    }
    --cnt;
}

int main() {

    scanf("%d%d", &N, &M);
    size = N; cnt = N;
    for (int i = 0; i < size; ++i) father[i + 1] = -1;
    father[0] = 0;
    add(1, size);
    for (int i = 0; i < M; ++i) {
        scanf("%s", &op);
        if (op == 'C') {
            scanf("%d%d", &x, &y);
            rt1 = find(x);
            rt2 = find(y);
            if (rt1 != 0 && rt2 != 0 && rt1 != rt2) merge(rt1, rt2);
        } else if (op == 'D') {
            scanf("%d", &x);
            rt = find(x);
            if (rt != 0) eat(rt);
        } else {
            scanf("%d", &x);
            printf("%d\n", findK(x));
        }
    }
    return 0;
}
