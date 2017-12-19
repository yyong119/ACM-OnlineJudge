#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x != 0 && x % 10 == 0) return false;
        int res = 0;   
        while(x > res) {
            res = res * 10 + x % 10;
            x /= 10;
        }   
        return (x == res) || (res /10 == x);
    }
};