#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int tmp = 0;
        int i = 0;
        int bit = 1;
        int len = str.length();
        if(len == 0) return 0;
        while(str[i] == ' ' && i < len) {
            ++i;
        }
        if(i == len) return 0;
        if(str[i] == '+') {
            bit = 1; ++i;
        } else if(str[i] == '-') {
            bit = -1; ++i;
        } else if(!(str[i] >= '0' && str[i] <= '9')) return 0;
        while(str[i] >= '0' && str[i] <= '9' && i < len) {
            //cout << str[i] << endl;
            tmp = res * 10 + (str[i] - '0') * bit;
            //cout << tmp;
            if(tmp / 10 != res) {
                if(bit == 1) return INT_MAX;
                else return INT_MIN; 
            }
            res = tmp;
            //cout << res;
            ++i;
        }
        return res;
    }
};