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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> s;
        if(!root) return 0;
        s.push(root);
        int sum = 0;
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            if(temp->left){
                s.push(temp->left);
                if((!temp->left->left) && (!temp->left->right)){
                    sum+=temp->left->val;
                }
            }
            if(temp->right){
                s.push(temp->right);
            }
        }
        return sum;
    }
};
