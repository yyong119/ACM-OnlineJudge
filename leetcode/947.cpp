class Solution {
public:
    static const int MAX_N = 1000;
    int parent[MAX_N + 5];
    int find_par(int x) {
        if (parent[x] != x)
            parent[x] = find_par(parent[x]);
        return parent[x];
    }
    void union_par(int x, int y) {
        int x_par = find_par(x), y_par = find_par(y);
        parent[x_par] = y_par;
    }
    static bool cmp1(vector<int> &p, vector<int> &q) {
        return p[0] < q[0];
    }
    static bool cmp2(vector<int> &p, vector<int> &q) {
        return p[1] < q[1];
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        if (n == 1) return 0;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            stones[i].push_back(i);
        }

        sort(stones.begin(), stones.end(), cmp1);
        for (int i = 1; i < n; ++i)
            if (stones[i][0] == stones[i - 1][0]) union_par(stones[i - 1][2], stones[i][2]);
        // for (int i = 0; i < n; ++i) cout << find_par(i) << " ";
        cout << endl;
        sort(stones.begin(), stones.end(), cmp2);
        for (int i = 1; i < n; ++i)
            if (stones[i][1] == stones[i - 1][1]) union_par(stones[i - 1][2], stones[i][2]);
        // for (int i = 0; i < n; ++i) cout << find_par(i) << " ";

        int ans = n;
        bool flag[n]; memset(flag, false, sizeof(flag));
        for (int i = 0; i < n; ++i) {
            int p = find_par(i);
            if (!flag[p]) {
                flag[p] = true;
                --ans;
            }
        }
        return ans;
    }
};