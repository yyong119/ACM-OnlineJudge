class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int pre_xor[n]; pre_xor[0] = arr[0];
        for (int i = 1; i < n; ++i)
            pre_xor[i] = pre_xor[i - 1] ^ arr[i];
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i)
            ans.push_back(pre_xor[queries[i][1]] ^ pre_xor[queries[i][0]] ^ arr[queries[i][0]]);
        return ans;
    }
};
