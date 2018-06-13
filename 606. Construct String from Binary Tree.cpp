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
    string tree2str(TreeNode* t) {
        string res;
        if(t==NULL) return "";
        res += to_string(t->val);
        if(t->left || t->right)
        res = res + "(" + tree2str(t->left) +")";
        if(t->right){
            res = res + "(" + tree2str(t->right) +")";            
        }     
        return res;
    }
};
