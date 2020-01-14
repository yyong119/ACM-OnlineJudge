class Solution {
public:

    vector<int> id[26];

    int find_upper_bound(int k, int t) {
        int l = 0, r = id[k].size() - 1, mid;
        while (l < r - 2) {
            mid = (l + r) >> 1;
            if (id[k][mid] > t) r = mid;
            else if (id[k][mid] <= t) l = mid + 1;
        }
        for (mid = l; mid <= r; ++mid)
            if (id[k][mid] > t) break;
        return id[k][mid];
    }

    int numMatchingSubseq(string S, vector<string>& words) {
        
        for (int i = 0; i < S.length(); ++i) id[S[i] - 'a'].push_back(i);
        for (int i = 0; i < 26; ++i) id[i].push_back(0x3f3f3f3f);
        int n = words.size(), ans = n;
        for (int i = 0; i < n; ++i) {
            int l = words[i].length(), p = -1;
            for (int j = 0; j < l; ++j) {
                p = find_upper_bound(words[i][j] - 'a', p);
                if (p == 0x3f3f3f3f) {
                    --ans;
                    break;
                }
            }
        }
        return ans;
    }
};