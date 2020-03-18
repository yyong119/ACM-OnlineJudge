#include <iostream>
#include <cstring>
#define MAX_LEN 1010
using namespace std;
char a[MAX_LEN], b[MAX_LEN];
int diff[MAX_LEN];
int main() {
    cin >> a >> b;
    int cnt = 0;
    for (register int i = 0; i < strlen(a); ++i)
        if (a[i] != b[i])
            diff[cnt++] = i;
    if (!cnt || cnt == 2 && a[diff[0]] == b[diff[1]] && a[diff[1]] == b[diff[0]])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
