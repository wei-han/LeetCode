/**
https://leetcode.com/problems/kth-smallest-element-in-a-bst/discuss/63660/3-ways-implemented-in-JAVA-(Python):-Binary-Search-in-order-iterative-and-recursive
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
    int kthSmallest(TreeNode* root, int k) {
        int left_num = count(root->left);
        if(left_num >= k){
            return kthSmallest(root->left, k);
        }
        if(left_num+1 < k){
            return kthSmallest(root->right, k-left_num - 1);
        }
            
        return root->val;
    }
    
    int count(TreeNode* root){
        if(root == NULL) return 0;
        return 1+count(root->left) + count(root->right);
    }
};
