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

    typedef struct TreeNode* NODE;

    int myOwn(NODE root){

        if(!root)
            return 0;
        
        int leftHeight = myOwn(root->left) + 1;
        int rightHeight = myOwn(root->right) + 1;

        return max(leftHeight, rightHeight);
    }
    int maxDepth(TreeNode* root) {

        if(!root)
            return 0;
        
        int leftHeight = maxDepth(root->left) + 1;
        int rightHeight = maxDepth(root->right) + 1;

        return max(leftHeight, rightHeight);
    
    }
};