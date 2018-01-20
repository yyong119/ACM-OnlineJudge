#include <cstring>
#include <iostream>
using namespace std;
 
const int MAXN = 100, MAXNUM = 200;
 
int main() {

	ios::sync_with_stdio(false);
    int num[MAXN + 1];
    bool element[MAXN + 1][MAXNUM + 1];
    int n, opnum, tmp;
    char op;
    memset(num, 0, sizeof(num)); memset(element, false, sizeof(element));
    // scanf("%d", &n);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    	// scanf("%d", &num[i]);
    	cin >> num[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= num[i]; ++j) {
            // scanf("%d", &tmp);
            cin >> tmp;
            element[i][tmp] = true;
        }
    // scanf("%d", &opnum);
    cin >> opnum;
    while (opnum--) {
    	int temp1, temp2;
        // scanf("%s%d%d", &op, &temp1, &temp2);
        cin >> op >> temp1 >> temp2;
        if (op == '+') {
            for (int i = 0; i <= MAXNUM; ++i)
                if (element[temp2][i]) element[temp1][i] = true;
        }
        else if (op == '-') {
            for (int i = 0; i <= MAXNUM; ++i)
                if ((element[temp1][i])&&(element[temp2][i])) element[temp1][i] = false;
        }
        else {
            for (int i = 0; i <= MAXNUM; ++i)
                if ((element[temp1][i])&&(element[temp2][i])) element[temp1][i] = true;
                else element[temp1][i] = false;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= MAXNUM; ++j)
        	// if (element[i][j]) printf("%d ", j);
        	if (element[i][j]) cout << j << ' ';
        // printf("\n");
        cout << endl;
    }
    return 0;
}
