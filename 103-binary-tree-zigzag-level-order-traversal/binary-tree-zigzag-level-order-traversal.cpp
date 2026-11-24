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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root)
            return ans;
        
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){

            int m = q.size();
            vector<int> temp(m);
            int f = 1;

            for(int i = 0; i < m; i++){
                TreeNode* front = q.front();
                q.pop();

                temp[i] = front->val;
                
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                
            }

            // if(f == -1){
            //     reverse(temp.begin(), temp.end());
            // }

            // f *= -1;

            ans.push_back(temp);
        }


        int n = ans.size();

        for(int i = 0; i < n; i++){
            if(i % 2 == 1){
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};