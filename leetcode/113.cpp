/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> ans;
class Solution {
public:
    void dfs(TreeNode* root, int cur_sum, const int& target_sum, vector<int>& seq) {
        if (cur_sum == target_sum && root->left == nullptr && root->right == nullptr) {
            ans.push_back(seq);
            return;
        }
        if (root->left) {
            seq.push_back(root->left->val);
            dfs(root->left, cur_sum + root->left->val, target_sum, seq);
            seq.pop_back();
        }
        if (root->right) {
            seq.push_back(root->right->val);
            dfs(root->right, cur_sum + root->right->val, target_sum, seq);
            seq.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        ans.clear();
        if (root == nullptr) return ans;
        vector<int> tmp;
        tmp.push_back(root->val);
        dfs(root, root->val, sum, tmp);
        return ans;
    }
};