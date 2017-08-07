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
    vector<TreeNode*> generateTrees(int n) {
        
        if(n == 0){return {};}

        return subTree(1, n);      
    }
    
    vector<TreeNode*> subTree(int s, int t)
    {
        vector<TreeNode*> ret;
        if(s - t > 0) ret.push_back(0);
        if(s == t) ret.push_back( new TreeNode(s));
        if(s < t)
        {
            for(int i = s; i <= t; i++)
            {
                vector<TreeNode*> l = subTree(s, i-1);
                vector<TreeNode*> r = subTree(i+1, t);
                for(int j = 0; j < l.size(); j++)
                {
                    for(int k = 0; k < r.size(); k++)
                    {
                        TreeNode* root = new TreeNode(i);
                        root->left = l[j];
                        root->right = r[k];
                        
                        ret.push_back(root);
                    }                    
                }
            }                
        }
        return ret;
    }
};
