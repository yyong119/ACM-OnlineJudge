#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

char pre[27], mid[27];
char treeData[1001];

void buildTree(char *pstart, char *mstart, int len, int pos) {
    if (len > 0) {
        treeData[pos] = *pstart;
        int i;
        for (i = 0; i < len; ++i)
            if (mstart[i] == *pstart) break;
        buildTree(pstart + 1, mstart, i, pos * 2);
        buildTree(pstart + 1 + i, mstart + i + 1, len - i - 1, pos * 2 + 1);
    }
}

int main() {
    cin >> pre >> mid;
    int n = strlen(pre);
    buildTree(pre, mid, n, 1);
    int cnt = 0;
    for (int i = 1; i <= 1000 && cnt < n; ++i)
        if (treeData[i] != '\0') {
            cout << treeData[i] << " ";
            ++cnt;
        }
        else cout << "NULL ";
    return 0;
}
