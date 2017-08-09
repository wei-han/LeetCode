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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder ) {
        return create(inorder, postorder , 0, postorder.size()-1 ,0 , inorder.size()-1);
    }
    
    TreeNode* create(vector<int> inorder, vector<int> postorder , int is, int ie, int ps, int pe)
    {
        if(is > ie) return NULL;
        int mid = 0;    
        for(int i = is; i <= ie; i++)
        {
            if(inorder[i] == postorder[pe])
            {
                mid = i;
                break;
            }    
        }
        
        TreeNode* root = new TreeNode(postorder[pe]);
        root->left = create(inorder, postorder,  is, mid - 1, ps, pe+mid-ie-1);
        root->right = create( inorder, postorder, mid+1, ie, pe+mid-ie, pe-1);
            
        return root;
        
    }
};
