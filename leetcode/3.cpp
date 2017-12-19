#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        for(int i = 0; i < 256; ++i) hash[s[i]] = -1;
        vector<int> dp(s.length()+1);
        vector<int> g(s.length()+1);
        dp[0] = 1; hash[s[0]] = 0; g[0] = 1;
        int start = 0;
        for(int i = 1; i < s.length(); ++i) {
            if(hash[s[i]] < start) {
                g[i] = g[i-1] + 1;
            }
            else {
                start = hash[s[i]] + 1;
                g[i] = i + 1 - start;
            }
            hash[s[i]] = i;
            dp[i] = max(dp[i-1], g[i]);
        }
        return dp[s.length()-1];
    }
};