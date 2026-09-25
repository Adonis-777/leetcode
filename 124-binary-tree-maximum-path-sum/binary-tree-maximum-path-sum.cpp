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
    int maxSum = INT_MIN;

    int solve(NODE root){
        if(!root)
            return 0;

        int left_child = solve(root->left);
        int right_child = solve(root->right);

        int arch_answer = left_child + right_child + root->val;
        int either_left_or_right = max(left_child, right_child) + root->val;
        int only_root = root->val;

        maxSum = max({only_root, either_left_or_right, arch_answer, maxSum});

        return max(either_left_or_right, only_root);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};