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

    int ans = 0;
    void dfs(TreeNode* root, int currSum){
        
        if(!root){        
            return;
        }

        currSum = currSum * 10 + root->val;

        if(!root->left && !root->right){
            ans += currSum;
            return;
        }
        
        dfs(root->left, currSum);
        dfs(root->right, currSum);

        currSum /= 10;
    }
    int sumNumbers(TreeNode* root) {

        ans = 0;
        dfs(root, 0);
        return ans;
        
    }
};