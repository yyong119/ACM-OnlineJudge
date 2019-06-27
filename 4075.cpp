#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_A 1000010
#define MAX_B 100010
char a[MAX_A], b[MAX_B];
int c[MAX_B];

int main() {
    
    scanf("%s", &a[0]);
    scanf("%s", &b[0]);
    int len_a = strlen(a), len_b = strlen(b);
    c[0] = -1;
    int i = 0, j = -1;
    while (i < len_b)
        if (j == -1 || b[i] == b[j])
            c[++i] = ++j;
        else
            j = c[j];

    i = j = 0;
    while (i < len_a && j < len_b)
        if (j == -1 || a[i] == b[j]) {
            ++i; ++j;
        }
        else
            j = c[j];
    printf("%d\n", i -  j);
    return 0;
}