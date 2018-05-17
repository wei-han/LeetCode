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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        TreeNode* l = root;
        TreeNode* r = root;
        
        int hl = 0;
        int hr = 0;
        
        while(l){
            hl++;
            l=l->left;
        }
        
        while(r){
            hr++;
            r = r->right;
        }
        
        if(hl == hr) return pow(2, hl) - 1;
        return 1+countNodes(root->left) + countNodes(root->right);
    }
};
