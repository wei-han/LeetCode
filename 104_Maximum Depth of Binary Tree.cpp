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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int count= 0;
        if(!root) return 0;
        else{
            q.push(root);
        }
        
        while(!q.empty())
        {
            count++;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }            
        }
        return count;
    }
};
