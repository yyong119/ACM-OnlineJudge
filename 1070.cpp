#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_V 6010
#define MAX_N 305
using namespace std;
int K, V, N, ans;
struct Node {
    int weight, value;
    Node(int p = 0, int q = 0): weight(p), value(q) {} 
} code[MAX_N];
struct linkNode {
    int pos, code_id;
    linkNode(int p = 0, int q = 0): pos(p), code_id(q){}
};
vector<linkNode> link_map[MAX_V];
int cur_max_value[MAX_V];
priority_queue<int, vector<int>, greater<int> > q;
bool has_k_solution;
inline bool cmp(const Node &p, const Node &q) {
    // return p.weight != q.weight ? p.weight > q.weight : p.value > q.value;
    return p.value > q.value;
}
inline int read() {
    char ch = getchar(); int res = 0, flag = 1;
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    // if (ch == '-') flag = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    // return res * flag;
    return res;
}
void calc(int rest, int cur_value, int pre_code_id) {
    // find a solution
    if (!rest) {
        // number of saved solutions is less than K
        if (!has_k_solution) {
            q.push(cur_value);
            if (q.size() == K) has_k_solution = true;
        }
        else if (cur_value > q.top()) {// better than current worst solution
            q.pop(); q.push(cur_value);
        }
        return;
    }
    // worse than current worst solution saved in queue
    if (has_k_solution && cur_max_value[rest] + cur_value <= q.top()) return;
    // find links to zero
    for (register int i = 0; i < link_map[rest].size(); ++i)
        // only keep descending order to avoid duplicate solution
        if (link_map[rest][i].code_id < pre_code_id)
            calc(link_map[rest][i].pos, cur_value + code[link_map[rest][i].code_id].value, link_map[rest][i].code_id);
        else return;
}
int main() {
    K = read(), V = read(), N = read();
    for (register int i = 0; i < N; ++i)
        code[i].weight = read(), code[i].value = read();
    sort(code, code + N, cmp);
    // init link list
    link_map[0].push_back(linkNode(-1, -1));
    // create link map
    for (register int i = 0; i < N; ++i)
        for (register int j = V; j >= code[i].weight; --j)
            // if j can be reached from j - code[i].weight by i-th code
            if (!link_map[j - code[i].weight].empty()) {
                link_map[j].push_back(linkNode(j - code[i].weight, i));
                cur_max_value[j] = max(cur_max_value[j], cur_max_value[j - code[i].weight] + code[i].value);
            }
    calc(V, 0, MAX_N);
    while (!q.empty()) {
        ans += q.top(); q.pop();
    }
    printf("%d\n", ans);
    return 0;
}