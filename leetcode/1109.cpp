class Solution {
public:
    long long tree[20000 << 2];
    int tag[20000 << 2];
    void insert(int x, int l, int r, int tar_l, int tar_r, int val) {
        if (tar_l == l && tar_r == r) {
            tag[x] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (tar_r <= mid) insert(x << 1, l, mid, tar_l, tar_r, val);
        else if (tar_l > mid) insert(x << 1 | 1, mid + 1, r, tar_l, tar_r, val);
        else {
            insert(x << 1, l, mid, tar_l, mid, val);
            insert(x << 1 | 1, mid + 1, r, mid + 1, tar_r, val);
        }
        tree[x] = tree[x << 1] + tree[x << 1 | 1];
    }
    void push_down(int x, int l, int r) {
        tree[x] += tag[x] * (long long)(r - l + 1);
        tag[x << 1] += tag[x];
        tag[x << 1 | 1] += tag[x];
        tag[x] = 0;
    }
    int query(int x, int l, int r, int tar) {
        if (l == r) return tree[x] + tag[x];
        if (tag[x]) push_down(x, l, r);
        int mid = (l + r) >> 1;
        if (tar <= mid) return query(x << 1, l, mid, tar);
        else return query(x << 1 | 1, mid + 1, r, tar);
    }
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for (int i = 0; i < bookings.size(); ++i)
            insert(1, 1, n, bookings[i][0], bookings[i][1], bookings[i][2]);
        for (int i = 1; i <= n; ++i)
            ans[i - 1] = query(1, 1, n, i);
        return ans;
    }
};
