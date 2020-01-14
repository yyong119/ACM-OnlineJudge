class Solution {
public:
    int par[100005];
    bool flag[100005];
    int find_parent(int k) {
        if (par[k] != k)
            par[k] = find_parent(par[k]);
        return par[k];
    }
    void union_parent(int p, int q) {
        int a = find_parent(p), b = find_parent(q);
        par[a] = b;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int lines = connections.size();
        if (lines < n - 1) return -1;
        for (int i = 0; i < n; ++i) par[i] = i;
        for (int i = 0; i < lines; ++i)
            union_parent(connections[i][0], connections[i][1]);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int p = find_parent(i);
            if (!flag[p]) {
                flag[p] = true;
                ++ans;
            }
        }
        for (int i = 0; i < n; ++i) cout << find_parent(i) << " ";
        return ans - 1;
    }
};