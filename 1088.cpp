#include <iostream>
using namespace std;
int n;
int map[16][16];
int cost;
bool flag[16];
 
void dfs(int depth, int temp, int pos) {
 
    if (temp >= cost) return;
    if (depth == n){
        if (temp + map[pos][1] < cost) cost = temp +map[pos][1];
        return;
    }
    for (int i = 2; i <= n; i++)
    if ((!flag[i])&&(i != pos)) {
        flag[i] = true;
        dfs(depth+1, temp + map[pos][i], i);
        flag[i] = false;
    }
}
int main() {
 
    cin>>n;
    cost = 2000 * 15;
 
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        cin>>map[i][j];
    }
    dfs(1,0,1);
    cout<<cost;
}