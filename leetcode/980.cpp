class Solution {
public:
    
    int ans = 0, start_x, start_y, number_of_steps;
    const int steps[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void dfs(int depth, int cur_x, int cur_y, const int &n, const int &m, vector<vector<int>>& grid) {
        
        for (int i = 0; i < 4; ++i) {
            
            int next_x = cur_x + steps[i][0], next_y = cur_y + steps[i][1];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m)
                if (grid[next_x][next_y] == 2 && depth == number_of_steps) ++ans;
                else if (!grid[next_x][next_y]) {
                    grid[next_x][next_y] = 1;
                    dfs(depth + 1, next_x, next_y, n, m, grid);
                    grid[next_x][next_y] = 0;
                }
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        number_of_steps = n * m - 1;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1) {
                    start_x = i; start_y = j;
                }
                else if (grid[i][j] == -1) --number_of_steps;
        
        dfs(1, start_x, start_y, n, m, grid);
        return ans;
    }
};