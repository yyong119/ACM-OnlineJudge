#include <iostream>
#include <cstring>
using namespace std;

bool block[10][3][3], row[10][9], col[10][9];

bool isOk(int n, int i, int j) {
    return (block[n][i / 3][j / 3] && row[n][i] && col[n][j]);
}

int ansNum(int arr[][9], int i, int j) {
    int count = 0;
    if (i == 9) return 1;//终止条件。
    if (arr[i][j] == 0) {//为0才填入。
        for (int n = 1;n <= 9;++n) {
            if (isOk(n, i, j)) {
                block[n][i / 3][j / 3] = row[n][i] = col[n][j] = false;
                switch (ansNum(arr, i + (j + 1) / 9, (j + 1) % 9)) {
                case 1:
                    if (++count > 1) return 2;
                    break;
                case 2:
                    return 2;
                }
                block[n][i / 3][j / 3] = row[n][i] = col[n][j] = true;//回溯。
            }
        }
        return count;
    }
    else return ansNum(arr, i + (j + 1) / 9, (j + 1) % 9);
}

bool initBool(int arr[][9]) {
    int count = 0;
    for (int n = 1;n <= 9;++n) {
        int i, j;
        for (i = 0;i < 3;++i)
            for (j = 0;j < 3;++j)
                block[n][i][j] = true;
        for (i = 0;i < 9;++i) row[n][i] = col[n][i] = true;
        for (i = 0;i<9;++i)
            for (j = 0;j<9;++j)
                if (arr[i][j] == n) {
                    ++count;
                    if (!block[n][i / 3][j / 3] || !row[n][i] || !col[n][j]) return false;//检查初始数据是否违规。
                    block[n][i / 3][j / 3] = row[n][i] = col[n][j] = false;
                }
    }
    return (count >= 17);//至少17个已知数据。
}

int main() {

    ios::sync_with_stdio(false);
    int T; cin >> T;
    int sudoku[9][9];
    memset(sudoku, sizeof(sudoku), 0);
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < 9; ++j)
            for (int k = 0; k < 9; ++k) cin >> sudoku[j][k];
        if (!initBool(sudoku)) cout << "No" << endl;
        else cout << (ansNum(sudoku, 0, 0) == 1 ? "Yes" : "No") << endl;
    }
    return 0;
}
