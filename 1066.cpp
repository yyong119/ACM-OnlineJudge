#include <iostream>
#include <string>
#include <vector>
using namespace std;

int clist[26], state[2005][2005];
string ori_name;
int N, M;

int CalCost(int l, int r) {
    int i, tem_cost1, tem_cost2, left, right;

    if (l >= r) return 0;
    if (ori_name[l] == ori_name[r]) return CalCost(++l,--r);
    if (state[l][r] >= 0) return state[l][r];
    left = ori_name[l] - 'a';
    right = ori_name[r] - 'a';
    tem_cost1 = clist[left] + CalCost(l + 1, r);
    tem_cost2 = clist[right] + CalCost(l, r - 1);
    int min_cost = tem_cost1 < tem_cost2 ? tem_cost1 : tem_cost2;
    state[l][r] = min_cost;
    return min_cost;
}

int main(){
    
    cin >> N >> M >> ori_name;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j) state[i][j] = -1;
    
    for (int i = 0; i < N; ++i) {
        int acost, dcost;
        char cha;
        cin >> cha >> acost >> dcost;
        clist[cha - 'a'] = acost < dcost ? acost : dcost;
    }
    int min_cost = CalCost(0, M - 1);
    cout << min_cost;
    
    return 0;
}
