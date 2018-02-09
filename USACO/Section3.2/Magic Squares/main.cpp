/*
ID: forusac5
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>
#include <cassert>
#define MMset(a,b) memset(a,b,sizeof(a))
using namespace std;
int trans[3][8]= {{7,6,5,4,3,2,1,0}, {3,0,1,2,5,6,7,4}, {0,6,1,3,4,2,5,7}};
map<string, pair<int, string> > state;
queue<pair<string, pair<int, string> > > Q;
map<string, int> in;
char ret[1000];
int main()
{
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);
    string init = "12345678";
    string goal = "";
    for (int i = 0; i < 8; i++) {
        int num;
        scanf("%d", &num);
        goal += (num + '0');
    }
    if (init == goal) {
        cout <<0<<endl<<endl;
        return 0;
    }
    state.insert(make_pair(init, make_pair(0, "")));
    Q.push(make_pair(init, make_pair(0, "")));
    in[init] = 1;
    while (!Q.empty()) {

        string nowState = Q.front().first;
        int nowStep = Q.front().second.first;
        string path = Q.front().second.second;
        in[nowState] = 0;
        for (int i = 0; i < 3; i++) {
            string next = "";
            for (int j = 0; j < 8; j++) {
                next += nowState[trans[i][j]];
            }

            string nextPath = path + char(i + 'A');
            pair<int, string> nextState = make_pair(nowStep + 1, nextPath);
            if (state.find(next) == state.end()) {
                state.insert(make_pair(next, nextState));
                Q.push(make_pair(next, nextState));
            } else {
                if (state[next] > nextState) {
                    state[next] = nextState;
                    if (in[next] == 0) {
                        in[next] = 1;
                        Q.push(make_pair(next, nextState));
                    }
                }
            }
        }
        Q.pop();
    }

    cout << state[goal].first<<endl;
    strcpy(ret ,state[goal].second.c_str());
    int len = strlen(ret);
    for (int i = 0; i < len; i += 60) {
        printf("%.60s\n", ret + i);
    }
    return 0;
}
