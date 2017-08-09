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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> item;
        vector<vector<int>> ans;
        TreeNode* temp;
        if(root==0) return ans;
        else q.push(root);
        
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0 ; i < n; i++ )
            {
                temp = q.front();
                q.pop();
                item.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.insert(ans.begin(), item);
            item = {};
        }
        
        
        return ans;
        
    }
};
