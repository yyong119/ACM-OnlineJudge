class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        sort(A.begin(), A.end());
        for (int i = 0; i < B.size(); ++i) {
            bool flag = false;
            for (int j = 0; j < A.size(); ++j)
                if (A[j] > B[i]) {
                    ans.push_back(A[j]);
                    A.erase(A.begin() + j);
                    flag = true;
                    break;
                }
            if (!flag) {
                ans.push_back(A[0]);
                A.erase(A.begin());
            }
        }
        return ans;
    }
};