#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int num[4000];

int main(){

    int n;
    cin >> n;
    memset(num, 0, sizeof(num));
    num[0] = 1;
    num[1] = 1;
    for (int i = 2; i <= n; ++i){
        num[i] += num[i - 1];
        for (int j = 1; j < i; ++j){
            num[i] += num[j - 1] * num[i - j - 1];
            num[i] %= 19301;
        }
        
    }
    cout << num[n] << endl;
    
    return 0;
}
