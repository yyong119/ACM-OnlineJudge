class Solution {
public:

    int find_max(vector<int>& A, int h, int t) {
        int tmp = A[h];
        for (int i = h + 1; i <= t; ++i)
            tmp = max(tmp, A[i]);
        return tmp;
    }

    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        int f[n]; memset(f, 0, sizeof(f));
        f[0] = A[0];
        for (int i = 1; i < n; ++i)
            for (int j = max(-1, i - K); j < i; ++j) {
                int tmp;
                if (j == -1) tmp = 0;
                else tmp = f[j];
                f[i] = max(f[i], tmp + find_max(A, j + 1, i) * (i - j));
            }
        for (int i = 0; i < n; ++i) cout << f[i] << " ";
        return f[n - 1];
    }
};