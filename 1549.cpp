#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char str[110],cha[110];
int point;
 
int main() {
 
    while (scanf("%s", str) != EOF) {
        point = 0;
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            cha[i] = ' ';
            if (str[i] == '(') ++point;
            if (str[i] == ')') {
                --point;
                if (point < 0) {
                    point = 0; cha[i] = '?';
                }
            }
        }
        point = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (str[i] == ')') ++point;
            if (str[i] == '(') {
                    --point;
                    if (point < 0) {
                        point = 0; cha[i] = '$';
                    }
                }
        }
        printf("%s\n%s\n", str, cha);
    }
}