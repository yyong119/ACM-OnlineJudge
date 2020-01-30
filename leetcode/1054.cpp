class Solution {
public:
    struct Node {
        int val, nums;
        Node(int p = 0, int q = 0) :val(p), nums(q) {}
    };
    static bool cmp(Node &a, Node &b) {
        return a.nums > b.nums;
    }
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> amounts;
        int N = barcodes.size();
        vector<int> nums, ans(N, 0);

        for (int i = 0; i < N; ++i) {
            ++amounts[barcodes[i]];
            if (amounts[barcodes[i]] == 1)
                nums.push_back(barcodes[i]);
        }

        vector<Node> A;
        for (int i = 0; i < nums.size(); ++i)
            A.push_back(Node(nums[i], amounts[nums[i]]));
        sort(A.begin(), A.end(), cmp);
        
        int idx = -2;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[i].nums; ++j) {
                idx += 2;
                if (idx >= N) idx = 1;
                ans[idx] = A[i].val;
            }
        }
        return ans;
    }
};
