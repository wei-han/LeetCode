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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == 0 ) return false;
        if(root->val == sum && root->left == 0 && root->right ==0) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        
    }
};
