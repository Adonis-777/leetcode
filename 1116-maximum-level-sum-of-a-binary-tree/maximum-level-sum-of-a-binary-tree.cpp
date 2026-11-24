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
    int maxLevelSum(TreeNode* root) {

        int level = 1;
        int last_level = height(root);

        queue<TreeNode*> q;
        q.push(root);

        long long max_sum = -1e9;
        int ans_level;

        while(!q.empty()){

            int n = q.size();
            long long sum = 0;

            for(int i = 0; i < n; i++){

                TreeNode* front = q.front();
                q.pop();

                sum += (long long)front->val;

                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);


            }

            if(sum > max_sum){
                max_sum = sum;
                ans_level = level;
            }

            level++;
        }

        return ans_level;

        
    }
};