#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {     
        int len_s = s.length();
        int len_p = p.length();
        int **dp = new int* [len_s+1];
        for(int i = 0; i <= len_s; ++i)
            dp[i] = new int[len_p+1]();
        
        // for(int i = 0; i < len_s; ++i)
        //     for(int j = 0; j < len_p; ++j)
        //         cout << dp[i][j] << endl;

        dp[0][0] = 1;
        for(int i = 0; i <= len_p; ++i) {
            if(p[i] == '*' && dp[0][i-1])
                dp[0][i+1] = 1;
        }
        for(int i = 0; i < len_s; ++i) {
            for(int j = 0; j < len_p; ++j) {
                if(p[j] == '.')
                    dp[i+1][j+1] = dp[i][j];
                else if(p[j] == s[i])
                    dp[i+1][j+1] = dp[i][j];
                else if(p[j] == '*') {
                    if(p[j-1] != s[i] && p[j-1] != '.')
                        dp[i+1][j+1] = dp[i+1][j-1];
                    else    
                        dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1];
                }
            }
        }
        return dp[len_s][len_p];
    }
};