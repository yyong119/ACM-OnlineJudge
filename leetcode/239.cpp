class Solution {
public:
    struct Node {
        int val, idx;
        Node(int p = 0, int q = 0) :val(p), idx(q) {}
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        if (!n || n < k) return ans;
        Node dq[n];
        int h = 0, t = 0;
        for (int i = 0; i < n; ++i) {
            if (t > h && dq[h].idx <= i - k)
                ++h;
            while (t > h && dq[t - 1].val < nums[i])
                --t;
            dq[t++] = Node(nums[i], i);
            if (i >= k - 1)
                ans.push_back(dq[h].val);
        }
        return ans;
    }
};
