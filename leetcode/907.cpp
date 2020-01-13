class Solution {
public:
    const int m = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A) {
        if (A.size() == 1) return A[0];
        int n = A.size();
        int left[n], right[n];

        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && A[st.top()] > A[i]) st.pop();
            if (st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && A[st.top()] >= A[i]) st.pop();
            if (st.empty()) right[i] = n;
            else right[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += A[i] * (i - left[i]) * (right[i] - i);
            ans %= m;
        }
        return ans;
    }
};