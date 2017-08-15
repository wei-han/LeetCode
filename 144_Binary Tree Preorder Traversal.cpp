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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> temp;
        TreeNode* curr;
        if(root) temp.push(root);
        else return ans;
        
        while(!temp.empty())
        {
            curr = temp.top();
            temp.pop();
            ans.push_back(curr->val);
            
            if(curr->right) temp.push(curr->right);
            if(curr->left) temp.push(curr->left);
        }
        
        return ans;
        
        
    }
};
