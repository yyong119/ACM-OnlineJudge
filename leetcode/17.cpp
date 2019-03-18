class Solution {
public:
    
    const string map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    int getIndex(char p) { return p - '2'; }
    
    void getString(int depth, string digits, string tmp) {

        int idx = getIndex(digits[depth]);
        for (int i = 0; i < map[idx].length(); ++i) {
            if (depth == digits.length() - 1)
                ans.push_back(tmp + map[idx][i]);
            else
                getString(depth + 1, digits, tmp + map[idx][i]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string tmp;
        if (digits.length() == 0) return ans;
        getString(0, digits, "");
        // int f_idx = getIndex(digits[0]);
        // for (int i = 0; i < map[f_idx].length(); ++i) {
        //     tmp = map[f_idx][i];
        //     getString(1, digits, tmp);
        // }
        return ans;
    }
};