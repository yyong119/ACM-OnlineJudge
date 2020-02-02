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
    void create_tree(TreeNode *head, vector<int>& nums, int ll, int lr, int rl, int rr) {
        if (lr > ll) {
            int max_l = ll;
            for (int i = ll + 1; i < lr; ++i)
                if (nums[i] > nums[max_l])
                    max_l = i;
            TreeNode *head_l = new TreeNode(nums[max_l]);
            head->left = head_l;
            create_tree(head_l, nums, ll, max_l, max_l + 1, lr);
        }
        if (rr > rl) {
            int max_r = rl;
            for (int i = rl + 1; i < rr; ++i)
                if (nums[i] > nums[max_r])
                    max_r = i;
            TreeNode *head_r = new TreeNode(nums[max_r]);
            head->right = head_r;
            create_tree(head_r, nums, rl, max_r, max_r + 1, rr);
        }
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            TreeNode *root = nullptr;
            return root;
        }
        int max_id = 0;
        for (int i = 1; i < n; ++i)
            if (nums[i] > nums[max_id]) max_id = i;
        TreeNode *root = new TreeNode(nums[max_id]);
        create_tree(root, nums, 0, max_id, max_id + 1, n);
        return root;
    }
};
