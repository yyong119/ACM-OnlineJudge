#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int find(string s, int index, int len, int &res_left, int &res_right) {
        int i = index, j = index;
        int left = index, right = index;
        res_left = index;
        res_right = index;
        int res1 = 0, res2 = 0;
        for(; i >= 0 && j < len; --i, ++j) {
            if(s[i] == s[j]) {
                res1 = j - i + 1;
                left = i; right = j;
            }
            else {
                break;
            }
        }
        if(index < len - 1 && s[index+1] == s[index]) {
            j = index + 1; i = index;
            for(; i >= 0 && j < len; --i, ++j) {
                if(s[i] == s[j]) {
                    res2 = j - i + 1;
                    res_left = i; res_right = j;
                    //cout << res_left << " " << res_right << " " << endl;
                }
                else {
                    break;
                }
            }
        }
        if(res2 > res1) {
            return res2;
        } else {
            res_left = left;
            res_right = right;
            return res1;
        }
    }

    string longestPalindrome(string s) {
        int len = s.length();
        int Max = 0;
        int res_left, res_right;
        int left, right;
        for(int i = 0; i < len; ++i) {
            int res = find(s, i, len, res_left, res_right);
            //cout << res_left << " " << res_right;
            if(res > Max) {
                Max = res;
                left = res_left;
                right = res_right;
            }
            
        }
        return s.substr(left, right - left + 1);
    }
};
