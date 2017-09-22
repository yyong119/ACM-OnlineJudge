#include <iostream>
#include <cstring>
using namespace std;
char p[1001], q[1001];
int i, j, lp, lq, maxlen;
int f[1001][1001];
int main() {
    cin>>p>>q;
    lp = strlen(p); lq = strlen(q);
    for (i = 1; i <= lp; i++)
        for (j = 1; j <= lq; j++){
            if (p[i - 1] != q[j - 1]){
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            } else {
                f[i][j] = f[i - 1][j - 1] +1;
            }
        }
    for (i = 0; i <= lp; i++)
        for (j = 0; j <= lq; j++)
        maxlen  = max(maxlen, f[i][j]);
    cout<<maxlen;
}