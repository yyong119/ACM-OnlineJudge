#include <iostream>
#define MAX_R 1010
using namespace std;

int state[MAX_R][MAX_R], triangle[MAX_R][MAX_R];

int main() {

    ios::sync_with_stdio(false);

    int R; cin >> R;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j <= i; ++j)
            cin >> triangle[i][j];
    for (int i = 0; i <= R - 1; ++i)
        state[R - 1][i] = triangle[R - 1][i];
    for (int i = R - 2; i >= 0; --i)
        for (int j = 0; j <= i; ++j)
            state[i][j] = (state[i + 1][j] > state[i + 1][j + 1] ? state[i + 1][j] : state[i + 1][j + 1]) + triangle[i][j];
    cout << state[0][0] << endl;

    return 0;
}
