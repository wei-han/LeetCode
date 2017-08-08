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
    bool isSymmetric(TreeNode* root) {
        if(root == 0) return true;
        queue<TreeNode *> q1, q2;
        TreeNode *left, *right;
        
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty())
        {
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            
            if(left==0 && right==0) continue;
            else if(left == 0 || right == 0) return false;
            
            if(left->val != right->val) return false;
            
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==0) return true;
        return judge(root->left, root->right);
        
        
    }
    
    bool judge(TreeNode* s, TreeNode* t)
    {
        if(s==0 && t == 0) return true;
        else if(s==0 || t==0) return false;
        
        if(s->val != t->val) return false;
        
        return judge(s->left, t->right) && judge(s->right, t->left);
    }
};
