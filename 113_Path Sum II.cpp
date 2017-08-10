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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> item;
        
        create(ans, item, root, sum);
        return ans;
        
    }
    
    void create(vector<vector<int>> &ans, vector<int> item, TreeNode* root, int sum)
    {
        if(root==0) return;
        
        item.push_back(root->val);
        if(root->val == sum && root->left==0 && root->right == 0)
        {
            ans.push_back(item);
            return;
        }
        create(ans, item, root->left, sum - root->val);
        create(ans, item, root->right, sum - root->val);
    }
};
