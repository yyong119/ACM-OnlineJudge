class Solution {
public:
    struct Node {
        int val, id;
        Node(int p = 0, int q = 0) :val(p), id(q) {}
    };
    static bool cmp(Node &a, Node &b) {
        if (a.val != b.val) return a.val < b.val;
        return a.id < b.id;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n, -1);
        if (!n || n == 1) return ans;
        Node head[n], tail[n];
        for (int i = 0; i < n; ++i) {
            head[i].val = intervals[i][0];
            head[i].id = i;
            tail[i].val = intervals[i][1];
            tail[i].id = i;
        }
        sort(head, head + n, cmp);
        sort(tail, tail + n, cmp);
        int h = 0, t = 0;
        while (h < n && t < n) {
            while (h < n && head[h].val < tail[t].val) ++h;
            if (h < n)
                ans[tail[t++].id] = head[h].id;
        }
        return ans;
    }
};
