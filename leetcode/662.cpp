/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct Node {
        int depth;
        double idx;
        TreeNode* root;
        Node(int p, double q, TreeNode* r) : depth(p), idx(q), root(r) {}
    };
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        vector<double> l, r;
        queue<Node> q; q.push(Node(0, 1, root));
        while (!q.empty()) {
            Node cur = q.front(); q.pop();
            if (l.size() == cur.depth) {
                l.push_back(cur.idx);
                r.push_back(cur.idx);
            }
            else {
                l[cur.depth] = min(l[cur.depth], cur.idx);
                r[cur.depth] = max(r[cur.depth], cur.idx);
            }
            if (cur.root->left)
                q.push(Node(cur.depth + 1, cur.idx * 2, cur.root->left));
            if (cur.root->right)
                q.push(Node(cur.depth + 1, cur.idx * 2 + 1, cur.root->right));
        }
        double ans = 0;
        for (int i = 0; i < l.size(); ++i)
            ans = max(ans, r[i] - l[i] + 1);
        return (int)ans;
    }
};