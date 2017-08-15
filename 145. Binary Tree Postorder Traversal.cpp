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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> temp;
        
        if(root) temp.push(root);
        else return ans;
        
        TreeNode *curr;
        while(!temp.empty())
        {
            curr = temp.top();
            
            if( !curr->right && !curr->left)
            {
                ans.push_back(curr->val);
                temp.pop();
            }
            if(curr->right) 
            {
                temp.push(curr->right);
                curr->right = NULL;
            }
            if(curr->left)
            {
                temp.push(curr->left);
                curr->left = NULL;
            }
            

        }
        return ans;
        
    }
};
