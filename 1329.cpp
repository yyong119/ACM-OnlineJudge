#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX_N 25
#define MAX_M 65
using namespace std;

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        vector<vector<int> > orders; 
        vector<int> _unused;
        orders.push_back(_unused);
        int n, m, tmp, sign; scanf("%d%d", &n, &m);
        char a = getchar();
        for (int i = 0; i < m; ++i) {
            // nmdwsm读一行数据都那么累
            vector<int> order; tmp = 0; sign = 1;
            while(true) {
                a = getchar();
                if (a == '\n') {
                    // 只有一个数字， 无数字读入为0，order为空
                    if (tmp) order.push_back(tmp * sign);
                    break;
                }
                else if (a == '-')
                    sign = -1;
                else if(a >= '0' && a <= '9')
                    tmp = tmp * 10 + a - '0';
                else if (a == ' ') {
                    order.push_back(tmp * sign);
                    sign = 1;
                    tmp = 0;
                }
            }
            orders.push_back(order);
        }

        // Check自己的读入有没有错
        // printf("\n");
        // for (int i = 1; i < orders.size(); ++i) {
        //     for (int j = 0; j < orders[i].size(); ++j)
        //         printf("%d ", orders[i][j]);
        //     printf("\n");
        // }

        // return 0;
        
        bool overall_OK = false;
        // 遍历各种菜被选择和不选择情况
        for (int order_case = 0; order_case < (1 << n); ++order_case) {
            int order_each[MAX_N], tmp = order_case;
            for (int i = 1; i <= n; ++i) {
                order_each[i] = tmp & 1; // 1选择第i个菜，0不选
                tmp >>= 1;
            }
            bool this_order_case_OK = true;
            // Check每个同学是否至少一项满足
            for (int i = 1; i <= m; ++i) {
                bool for_this_user_OK = false;
                if (orders[i].size() == 0)
                    for_this_user_OK = true;
                else
                    for (int j = 0; j < orders[i].size(); ++j) {
                        int num = orders[i][j];
                        // num为正即该同学喜欢这个菜， num为负即该同学讨厌这个菜
                        if (num > 0 && order_each[num] == 1 || num < 0 && order_each[-num] == 0) {
                            for_this_user_OK = true;
                            break;
                        }
                    }
                // 一个同学无法满足，则这种情况不符合
                if (for_this_user_OK == false) {
                    this_order_case_OK = false;
                    break;
                }
            }
            // 这种情况符合，结束输出Bingo
            if (this_order_case_OK) {
                overall_OK = true;
                break;
            }
        }
        if(overall_OK)
            printf("Bingo!\n");
        else
            printf("Sigh...\n");
    }
    return 0;
}
