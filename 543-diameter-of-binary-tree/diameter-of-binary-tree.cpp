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

    int max_diameter = 0;
    int height(TreeNode* root){
        if(!root)
            return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);

        int curr_diameter = left_height + right_height;
        max_diameter = max(max_diameter, curr_diameter);

        return (1 + max(left_height, right_height));
    }
    int diameterOfBinaryTree(TreeNode* root) {

        // maximum number of edges between nodes

        int h = height(root);
        return max_diameter;
        
    }
};