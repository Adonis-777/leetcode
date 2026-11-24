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

    int height(TreeNode* root){
        if(!root)
            return 0;
        
        int left_height = height(root->left);
        int right_height = height(root->right);

        return 1 + max(left_height, right_height);
    }
    int findBottomLeftValue(TreeNode* root) {

        queue<TreeNode*> q;

        if(!root->left && !root->right){
            return root->val;
        }

        q.push(root);
        int ans = INT_MIN;

        int level = 1;
        int last_level = height(root);



        while(!q.empty()){

            int n = q.size();
            for(int i = 0; i < n; i++){

                TreeNode* front = q.front();
                q.pop();

                if(i == 0 && level == last_level){
                    ans = max(ans, front->val);
                }

                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }

            level++;

        }

        return ans;
        
    }
};