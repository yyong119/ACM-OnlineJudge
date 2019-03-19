class Solution {
public:
        
    void solve(vector<string>& map, vector<int>& pos, int depth, int n, vector<vector<string>> & res) {
        if (depth == n) {
            res.push_back(map);
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            
            pos[depth] = i;
            if (valid(pos, depth)) {
                    map[depth][i] = 'Q';
                    solve(map, pos, depth + 1, n, res);
                    map[depth][i] = '.';
            }    
        } 
    }
    
    bool valid(vector<int>& pos, int curLen) {
        for (int i = 0; i < curLen; ++i)
            if (abs(pos[i] - pos[curLen]) == curLen - i || pos[i] == pos[curLen])
                return false;
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<string> map;
        string row(n, '.');
        for(int i = 0; i < n; i++) {
            map.push_back(row);
        }
        vector<int> pos = vector<int>(n);
        solve(map, pos, 0, n, res);
        
        return res;
    }
};