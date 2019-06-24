#include <iostream>
#include <algorithm>
using namespace std;

int m,n;
int map[55][55];
int dp[55][55][55];

int main(){

    ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> map[i][j];
    dp[0][0][0] = map[0][0];

    for (int i = 1; i < n; ++i)
        dp[0][0][i] = dp[0][0][i - 1] + map[0][i];

    for (int i = 1; i < m; ++i) // 层数
        for (int pre_l = 0; pre_l < n - 1; ++pre_l) // 第一个位置
            for (int pre_r = pre_l + 1; pre_r < n; ++pre_r) { //第二个位置，两个上层位置
                int tmp = dp[i - 1][pre_l][pre_r];
                for (int cur_l = pre_l; cur_l < pre_r; ++cur_l) { //当前层左边点平移后位置
                    tmp += map[i][cur_l];
                    int t = tmp;
                    for (int cur_r = pre_r; cur_r < n; ++cur_r) { // 当前层右边点平移后位置
                        t += map[i][cur_r];
                        dp[i][cur_l][cur_r] = max(dp[i][cur_l][cur_r], t);
                    }
                }
            }
    cout << dp[m - 1][n - 2][n - 1] << endl;
    // cout << dp[1][1][2] << endl;
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         for (int k = 0; k < n; ++k)
    //             cout << dp[i][j][k] << " ";
    //         cout << endl;
    //     }
    //     cout << endl;

    // }
    return 0;
}
