class Solution {
public:
    struct Node {
        int x, steps, color;
        // color: 0b10 blue, 0b01 red, 0b11 start node
        Node(int p, int q, int c) : x(p), steps(q), color(c) {}
    };

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {

        vector<int> ans_r(n, 0x3f3f3f3f), ans_b(n, 0x3f3f3f3f);
        vector<int> GR[n], GB[n];// graph_red, graph_green
        for (int i = 0; i < red_edges.size(); ++i)
            GR[red_edges[i][0]].push_back(red_edges[i][1]);
        for (int i = 0; i < blue_edges.size(); ++i)
            GB[blue_edges[i][0]].push_back(blue_edges[i][1]);

        queue<Node> q; q.push(Node(0, 0, 3));
        while(!q.empty()) {
            Node cur = q.front(); q.pop();
            // cout << cur.x << " " << cur.steps << " " << cur.color << endl;
            if (cur.color & 2) // reach x by blue or x == 0
                for (int i = 0; i < GR[cur.x].size(); ++i)
                    if (ans_r[GR[cur.x][i]] == 0x3f3f3f3f) {
                        ans_r[GR[cur.x][i]] = cur.steps + 1;
                        q.push(Node(GR[cur.x][i], cur.steps + 1, 1));
                    }
            if (cur.color & 1) // reach x by red or x == 0
                for (int i = 0; i < GB[cur.x].size(); ++i)
                    if (ans_b[GB[cur.x][i]] == 0x3f3f3f3f) {
                        ans_b[GB[cur.x][i]] = cur.steps + 1;
                        q.push(Node(GB[cur.x][i], cur.steps + 1, 2));
                    }
        }
        vector<int> ans(n, 0);
        for (int i = 1; i < n; ++i) {
            ans[i] = min(ans_b[i], ans_r[i]);
            if (ans[i] == 0x3f3f3f3f)
                ans[i] = -1;
        }
        return ans;
    }
};
