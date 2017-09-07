#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n, i, h, t, indexx;
int main() {
    queue<string> que[101];
    string temp;
    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) {
        getline(cin, temp);
        que[i].push(temp);
        }
    for (i = 1; i < n; i++) {
        scanf("%d%d", &t, &h);
        while (que[t].size()) {
            que[h].push(que[t].front());
            que[t].pop();
        }
    }
    for (indexx = 1; indexx <= n; indexx++) if (que[indexx].size()) break;
    while (que[indexx].size()) {
        cout<<que[indexx].front()<<" ";
        que[indexx].pop();
    }
    return 0;
}