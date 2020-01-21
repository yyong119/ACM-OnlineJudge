class Solution {
public:
    void insert(int tree[], int idx, int l, int r, int target) {
        if (l == r && l == target) {
            ++tree[idx];
            return;
        }
        int mid = (l + r) >> 1;
        if (target <= mid) insert(tree, idx << 1, l, mid, target);
        else insert(tree, idx << 1 | 1, mid + 1, r, target);
        tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
    }
    int query(int tree[], int idx, int l, int r, int tar_l, int tar_r) {
        if (l == tar_l && r == tar_r)
            return tree[idx];
        int mid = (l + r) >> 1;
        if (tar_r <= mid) return query(tree, idx << 1, l, mid, tar_l, tar_r);
        else if (tar_l > mid) return query(tree, idx << 1 | 1, mid + 1, r, tar_l, tar_r);
        else return query(tree, idx << 1, l, mid, tar_l, mid) + query(tree, idx << 1 | 1, mid + 1, r, mid + 1, tar_r);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), n2 = n << 1;
        if (n == 0) return 0;
        long long num[n2];
        for (int i = 0; i < n; ++i) num[i] = nums[i];
        for (int i = n; i < n2; ++i) num[i] = (long long)nums[i - n] * 2;
        // for (int i = 0; i < n2; ++i) cout << num[i] << " "; cout << endl;
        long long tmp[n2]; memcpy(tmp, num, sizeof(num));
        sort(tmp, tmp + n2);
        int cnt = unique(tmp, tmp + n2) - tmp;
        for (int i = 0; i < n2; ++i)
            num[i] = lower_bound(tmp, tmp + cnt, num[i]) - tmp + 1;
        // for (int i = 0; i < n2; ++i) cout << num[i] << " "; cout << endl;
        int tree[cnt << 2]; memset(tree, 0, sizeof(tree));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (num[i + n] + 1 <= cnt)
                ans += query(tree, 1, 1, cnt, num[i + n] + 1, cnt);
            insert(tree, 1, 1, cnt, num[i]);
        }
        return ans;
    }
};