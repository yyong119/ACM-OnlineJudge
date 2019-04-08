class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int i = 0, j = n - 1;
        while (true) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target)
                if (i < m - 1) ++i;
                else break;
            if (matrix[i][j] > target)
                if (j > 0) --j;
                else break;
        }
        return false;
    }
};