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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if (!root) return 0;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if (!cur->left && !cur->right) ans += cur->val;
            if (cur->left) {
                cur->left->val += cur->val * 10;
                q.push(cur->left);
            }
            if (cur->right) {
                cur->right->val += cur->val * 10;
                q.push(cur->right);
            }
        }
        return ans;
    }
};