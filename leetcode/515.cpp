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
    void dfs(TreeNode* root, int depth, vector<int>& ans) {
        if (depth >= ans.size()) ans.push_back(-0x80000000);
        ans[depth] = max(ans[depth], root->val);
        if (root->left) dfs(root->left, depth + 1, ans);
        if (root->right) dfs(root->right, depth + 1, ans);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        ans.push_back(root->val);
        dfs(root, 0, ans);
        return ans;
    }
};
