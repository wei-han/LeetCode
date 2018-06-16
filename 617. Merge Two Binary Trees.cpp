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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        stack<TreeNode*> stk1, stk2;
        if(t1==NULL) return t2;
        if(t2==NULL) return t1;
        
        stk1.push(t1);
        stk2.push(t2);
        
        TreeNode* res = t1;
        
        while(!stk1.empty()){
            TreeNode* temp1 = stk1.top();
            TreeNode* temp2 = stk2.top();
            
            stk1.pop();
            stk2.pop();
            
            temp1->val += temp2->val;
            if(temp1->left==NULL && temp2->left!=NULL) temp1->left = temp2->left;
            else if(temp1->left!=NULL && temp2->left!=NULL){
                stk1.push(temp1->left);
                stk2.push(temp2->left);
            } 
            if(temp1->right==NULL && temp2->right!=NULL) temp1->right = temp2->right;
            else if(temp1->right!=NULL && temp2->right!=NULL){
                stk1.push(temp1->right);
                stk2.push(temp2->right);
            } 
            
        }
        return res;
    }
};
