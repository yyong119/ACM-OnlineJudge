class Solution {
public:
    int cnt = 0;
    void solve(vector<string>& map, vector<int>& pos, int depth, int n) {
        if (depth == n)
            ++cnt;
        else        
            for (int i = 0; i < n; ++i) {

                pos[depth] = i;
                if (valid(pos, depth)) {
                        map[depth][i] = 'Q';
                        solve(map, pos, depth + 1, n);
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

    int totalNQueens(int n) {
        
        vector<string> map;
        string row(n, '.');
        for(int i = 0; i < n; i++) {
            map.push_back(row);
        }
        vector<int> pos = vector<int>(n);
        solve(map, pos, 0, n);
        
        return cnt;
    }
};