class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        int ans = A[n - 1] - A[0];
        for (int i = 0; i < n - 1; ++i) {
            int cur_max = max(A[n - 1] - K, A[i] + K);
            int cur_min = min(A[0] + K, A[i + 1] - K);
            ans = min(ans, cur_max - cur_min);
        }
        return ans;
    }
};
