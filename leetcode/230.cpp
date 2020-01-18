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
    int ans, cnt = 0;
    bool flag = false;
    void mid_order(TreeNode* cur_root, const int &target) {
        if (flag) return;
        if (cur_root->left) mid_order(cur_root->left, target);
        if (++cnt == target) {
            flag = true;
            ans = cur_root->val;
            return;
        }
        if (cur_root->right) mid_order(cur_root->right, target);
    }
    int kthSmallest(TreeNode* root, int k) {
        mid_order(root, k);
        return ans;
    }
};