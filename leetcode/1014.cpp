class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size(), ans = 0;
        int best_id = 0;
        for (int i = 1; i < n; ++i) {
            ans = max(ans, A[i] + A[best_id] - i + best_id);
            if (A[i] + i > A[best_id] + best_id)
                best_id = i;
        }
        return ans;
    }
};