/*
ID: forusac5
PROG: contact
LANG: C++
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <cassert>
#define MMset(a,b) memset(a,b,sizeof(a))
using namespace std;
char line[100], str[200100];
int cnt[13][1 << 12];
int A, B, N;
struct Node {
    int len, tot, num;
    Node (int _len = 0, int _tot = 0, int _num = 0) {
        len = _len;
        tot = _tot;
        num = _num;
    }
    char *state() {
        static char str[20];
        MMset(str, '\0');
        int tmp = num;
        for (int i = 0; i < len; i++) {
            str[i] = tmp % 2 + '0';
            tmp /= 2;
        }
        reverse(str, str + len);
        return str;
    }
};
vector <Node> vec;
bool cmp(Node a, Node b) {
    if (a.tot != b.tot) return a.tot > b.tot;
    else {
        if (a.len != b.len) return a.len < b.len;
        return a.num < b.num;
    }
}
int main()
{
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    scanf("%d%d%d", &A, &B, &N);
    while (scanf("%s", line) != EOF) {
        strcat(str, line);
    }
    int len = strlen(str);
    for (int i = A; i <= B; i++) {
        int mask = (1 << i) - 1, now = 0;
        for (int j = 0; j < len; j++) {
            now = now << 1;
            if (str[j] == '1')  now += 1;
            if (j >= i - 1) {
                now = now & mask;
                cnt[i][now]++;
            }
        }
    }
    for (int i = A; i <= B; i++) {
        for (int j = 0; j < (1 << i); j++) {
            if (cnt[i][j]) {
                vec.push_back(Node(i, cnt[i][j],j));
            }
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    int pre = -1, mod = 0;
    for (int i = 0, j = 0; i < (int)vec.size(); i++) {
        if (pre != vec[i].tot) {
            j++;
            if (j == N + 1) break;
            if (pre != -1)  puts("");
            pre = vec[i].tot;
            mod = 0;
            printf("%d\n", pre);
        }
        if (mod != 0 && mod % 6 == 0) printf("\n");
        else    if (mod % 6 != 0)             printf(" ");
        printf("%s", vec[i].state());
        mod = mod + 1;
    }
    puts("");
    return 0;
}
