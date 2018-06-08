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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        sub(root, count);
        return count;
    }
    
    bool sub(TreeNode* root, int& count){
        if(!root) return true;
        
        bool left = sub(root->left, count);
        bool right = sub(root->right, count);
        
        if(left && right && 
          (!root->left || root->val == root->left->val) &&
          (!root->right || root->val == root->right->val)){
            count++;
            return true;
        }
        
        return false;
    }
};


//false solution, only consider the nodes on the first level of the tree
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
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        if((!root->left ||root->val == root->left->val)
          &&(!root->right ||root->val == root->right->val)) res++;
        
        return res+countUnivalSubtrees(root->left)+countUnivalSubtrees(root->right);
    }
};
