#include <iostream>
#include <cstring>
using namespace std;

int a[105],b[105],c[105];
char p[105],q[105];
int i, length;

int main() {

    cin >> p >> q;
    for (i = 0; i <= strlen(p) - 1; ++i) a[strlen(p) - i] = int(p[i] - 'a');
    for (i = 0; i <= strlen(q) - 1; ++i) b[strlen(q) - i] = int(q[i] - 'a');
    if (strlen(p) >= strlen(q)) length = strlen(p);
        else length = strlen(q);
    for (i = 1; i <= length; ++i){
        c[i] += a[i] + b[i];
        c[i + 1] += c[i] / 26; c[i] = c[i] % 26;
    }
    if (c[length + 1]) length++;
    for (i = length; i >= 1; --i) cout << char('a' + c[i]);
	return 0;
}
