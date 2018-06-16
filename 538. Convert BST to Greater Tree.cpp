//inoder traverse, first right node then left node
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
    int cur = 0;
    TreeNode* convertBST(TreeNode* root) {
        con(root);
        return root;
    }
    
    void con(TreeNode* root){
        if(!root) return;
        
        con(root->right);
        cur+=root->val;
        root->val = cur;
        con(root->left);
    }
};
