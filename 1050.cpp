#include <cstdio>
#include <queue>
 
using namespace std;
 
int n, m, op, num1, num2;
priority_queue<int, vector<int>, greater<int> > group[300001];
 
int main() {
 
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num1);
        group[i].push(num1);
    }
 
    for (int opnum = 1; opnum <= m; opnum++) {
        scanf("%d", &op);
        switch (op) {
            case 0:
                scanf("%d%d", &num1, &num2);
                while(group[num2].size()) {
                    group[num1].push(group[num2].top());
                    group[num2].pop();
                }
                break;
            case 1:
                scanf("%d", &num1);
                if (group[num1].empty()) printf("%d\n", -1);
                else {
                    printf("%d\n", group[num1].top());
                    group[num1].pop();
                }
                break;
            case 2:
                scanf("%d%d", &num1, &num2);
                group[num1].push(num2);
                break;
        }
    }
    return 0;
}
