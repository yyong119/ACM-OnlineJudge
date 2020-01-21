class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> link[N + 1];
        for (int i = 0; i < dislikes.size(); ++i) {
            link[dislikes[i][0]].push_back(dislikes[i][1]);
            link[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        int colour[N + 1]; memset(colour, -1, sizeof(colour));
        queue<int> q;
        for (int i = 1; i <= N; ++i)
            if (colour[i] == -1) {
                colour[i] = 0;
                q.push(i);
                while(!q.empty()) {
                    int cur = q.front(); q.pop();
                    // cout << cur << endl;
                    // for (int j = 0; j < link[cur].size(); ++j)
                    //     cout << link[cur][j] << " ";
                    // cout << endl;
                    for (int j = 0; j < link[cur].size(); ++j)
                        if (colour[link[cur][j]] == colour[cur])
                            return false;
                        else {
                            if (colour[link[cur][j]] == -1)
                                q.push(link[cur][j]);
                            colour[link[cur][j]] = 1 - colour[cur];
                        }
                }
            }
        return true;
    }
};
