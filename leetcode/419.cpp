class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0, n = board.size();
        if (!n) return 0;
        int m = board[0].size();
        if (!m) return 0;
        if (board[0][0] == 'X') ++ans;
        for (register int i = 1; i < m; ++i)
            if (board[0][i] == 'X' && board[0][i - 1] == '.') ++ans;
        for (register int i = 1; i < n; ++i)
            if (board[i][0] == 'X' && board[i - 1][0] == '.') ++ans;
        for (register int i = 1; i < n; ++i)
            for (register int j = 1; j < m; ++j)
                if (board[i][j] == 'X' && board[i - 1][j] == '.' && board[i][j - 1] == '.')
                    ++ans;
        return ans;
    }
};