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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        proc(res, root, 1);
        return res;
    }
    
    void proc(vector<int> &res, TreeNode* root, int level)
    {
        if(root == 0) return;
        if(res.size() < level) res.push_back(root->val);
        proc(res, root->right, level+1);
        proc(res, root->left, level+1);
    }
};
