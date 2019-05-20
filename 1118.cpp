#include <iostream>
#include <cstdio>
#include <vector>
#define MAX_N 10010
using namespace std;

int n, m;
int father[MAX_N], num_of_cities[MAX_N];
vector<int> son[MAX_N];

int find(int x) {
    if (father[x] == x) return x;
    father[x] = find(father[x]);
    return father[x];
}

int main() {

    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
        son[i].push_back(i);
    }

    while (m--) {

        char op; cin >> op;
        if (op == 'T') {
            int group_id, des;
            cin >> group_id >> des;
            int cur_place = find(group_id);
            des = find(des);
            if (cur_place == des)
                continue;
            for (int i = 0; i < son[cur_place].size(); ++i)
                ++num_of_cities[son[cur_place][i]];
            son[des].insert(son[des].end(), son[cur_place].begin(), son[cur_place].end());
            son[cur_place].clear();
            father[find(cur_place)] = des;
        }
        else {
            int group_id;
            cin >> group_id;
            int cur_place = find(group_id);
            printf("%d %d %d\n", cur_place, son[cur_place].size(), num_of_cities[group_id]);
        }
    }

    return 0;
}
