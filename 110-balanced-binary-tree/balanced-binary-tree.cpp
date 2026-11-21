/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        int left_height = height(root->left);
        int right_height = height(root->right);

        int diff = left_height - right_height;
        if(diff < -1 || diff > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);

        // balance should be on left subtree and right subtree aswell
        // balance --> left-right should be -1, 0 or 1
    }
};