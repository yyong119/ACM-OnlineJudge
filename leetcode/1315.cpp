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
    int cal_sum_of_grandson(TreeNode* root) {
        int tmp = 0;
        if (root->left) {
            if (root->left->left) tmp += root->left->left->val;
            if (root->left->right) tmp += root->left->right->val;
        }
        if (root->right) {
            if (root->right->left) tmp += root->right->left->val;
            if (root->right->right) tmp += root->right->right->val;
        }
        return tmp;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if (cur->val % 2 == 0)
                ans += cal_sum_of_grandson(cur);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
        }
        return ans;
    }
};