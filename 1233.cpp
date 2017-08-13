#include <iostream>
#include <queue>
using namespace std;
 
int n, m, start, M, total;
bool visited[11];
queue<int> a[11];
void dfs(int depth, int pos) {
    
    if (depth == M + 1) {
        ++total;
        return;
    }
    queue<int> tmp = a[pos];
    while (!tmp.empty()) {
        int next = tmp.front();
        tmp.pop();
        if (!visited[next]) {
            visited[next] = true;
            dfs(depth + 1, next);
            visited[next] = false;
        }
    }
}
 
int main() {
 
    ios::sync_with_stdio(false);
 
    cin >> n >> m >> start >> M;
    for (int i = 1; i <= m; ++i) {
        int from, to;
        cin >> from >> to;
        a[from].push(to);
    }
    visited[start] = true;
    dfs(1, start);
    cout << total << endl;
    return 0;
}