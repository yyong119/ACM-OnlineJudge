struct node {
    int value, group;
    node(int p = 0, int q = 0) : value(p), group(q) {}
};
bool operator<(node a, node b) {
    return a.value > b.value;
}
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<node> numbers;
        int k = nums.size(), l = 1e5 + 5, r = -(1e5 + 5);
        int cnt[k]; memset(cnt, 0, sizeof(cnt));
        priority_queue<node> cur, all;
        for (int i = 0; i < k; ++i) {
            int n = nums[i].size();
            node tmp(nums[i][0], i);
            cur.push(tmp);
            ++cnt[i];
            l = min(l, nums[i][0]);
            r = max(r, nums[i][0]);
            for (int j = 1; j < n; ++j) {
                tmp.value = nums[i][j];
                all.push(tmp);
            }
        }
        int ans = r - l;
        vector<int> ans_p = {l, r};
        node cur_min, tmp;
        while (!all.empty()) {
            tmp = all.top(); all.pop(); //to be pushed
            cur_min = cur.top(); //to be poped
            cout << tmp.value << " " << cur_min.value << endl;
            while (cnt[cur_min.group] > 1) {
                cur.pop();
                l = cur.top().value;
                --cnt[cur_min.group];
                cur_min = cur.top();
            }
            if (r - l < ans) {
                ans_p[0] = l;
                ans_p[1] = r;
                ans = r - l;
            }
            r = max(r, tmp.value);
            cur.push(tmp);
            ++cnt[tmp.group];
        }
        while (cnt[cur_min.group] > 1) {
            cur.pop();
            l = cur.top().value;
            --cnt[cur_min.group];
            cur_min = cur.top();
        }
        if (r - l < ans) {
            ans_p[0] = l;
            ans_p[1] = r;
            ans = r - l;
        }
        return ans_p;
    }
};