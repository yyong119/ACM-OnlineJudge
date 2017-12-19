#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x) {
            int temp = res * 10 + x % 10;
            if(temp / 10 != res) return 0;
            res = temp;
            x /= 10;
        }
        return res;
    }
};