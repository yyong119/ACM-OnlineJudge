class Solution {
public:
    void insert(int tree[], int idx, int l, int r, int target) {
        if (l == r && l == target) ++tree[idx];
        else {
            int mid = (l + r) >> 1;
            if (target <= mid) insert(tree, idx << 1, l, mid, target);
            else insert(tree, idx << 1 | 1, mid + 1, r, target);
            tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
        }
    }
    int query(int tree[], int idx, int l, int r, int tar_l, int tar_r) {
        if (tar_r < tar_l) return 0;
        if (l == tar_l && r == tar_r) return tree[idx];
        int mid = (l + r) >> 1;
        if (tar_r <= mid) return query(tree, idx << 1, l, mid, tar_l, tar_r);
        else if (tar_l > mid) return query(tree, idx << 1 | 1, mid + 1, r, tar_l, tar_r);
        else return query(tree, idx << 1, l, mid, tar_l, mid) + query(tree, idx << 1 | 1, mid + 1, r, mid + 1, tar_r);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return nums;
        int tmp[n];
        for (int i = 0; i < n; ++i) tmp[i] = nums[i];
        sort(tmp, tmp + n);
        int cnt = unique(tmp, tmp + n) - tmp;
        for (int i = 0; i < n; ++i)
            nums[i] = lower_bound(tmp, tmp + cnt, nums[i]) - tmp + 1;
        int tree[cnt << 2]; memset(tree, 0, sizeof(tree));
        for (int i = n - 1; i >= 0; --i) {
            int tmp = query(tree, 1, 1, cnt, 1, nums[i] - 1);
            insert(tree, 1, 1, cnt, nums[i]);
            nums[i] = tmp;
        }
        return nums;
    }
};