class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int l = 0, r = 0;
        for (int i = 1; i < A.size(); ++i)
            if (A[i] < A[i - 1]) {
                l = i - 1;
                r = i;
            }
            else if (l != r && A[r] < A[i] && A[i] < A[l])
                r = i;
        int tmp = A[l];
        A[l] = A[r];
        A[r] = tmp;
        return A;
    }
};