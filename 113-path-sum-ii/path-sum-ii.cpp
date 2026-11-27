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

    void dfs(TreeNode* root, vector<int>& curr, int currSum, vector<vector<int>>& ans, int targetSum){

        if(!root){
            return;
        }

        currSum += root->val;
        curr.push_back(root->val);

        if(currSum == targetSum && !root->left && !root->right){
            ans.push_back(curr);            
        }

        else{        
            dfs(root->left, curr, currSum, ans, targetSum);
            dfs(root->right, curr, currSum, ans, targetSum);
        }

        currSum -= root->val;
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> curr;
        vector<vector<int>> ans;

        int currSum = 0;

        dfs(root, curr, currSum, ans, targetSum);
        return ans;
        
    }
};