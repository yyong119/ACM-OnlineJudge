#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        string res = "";
        if(len <= numRows) return s;
        if(numRows == 1) return s;
        
        for(int i = 0; i < numRows; ++i) {
            if(i == 0) {
                for(int j = 0; j < len; j = j + numRows*2-2)
                    res += s[j];
            } else if(i == numRows - 1) {
                for(int j = numRows - 1; j < len; j = j + numRows*2-2)
                    res += s[j];
            } else {
                for(int j = i; j < len; j = j + numRows*2-2) {
                    res += s[j];
                    if(j + 2*(numRows-1-i) < len) {
                        res += s[j + 2*(numRows-1-i)];
                    }
                }
            }
        }
        return res;
    }
};