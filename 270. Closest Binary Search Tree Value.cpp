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
    int closestValue(TreeNode* root, double target) {
        int closet = root->val;
        while(root){
            if(abs(root->val-target) <= abs(closet-target))
                closet = root->val;
            root = target < root->val ? root->left : root->right;
        }
        return closet;
    }
};

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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        root = closest < target ? root->right : root-> left;
        if(!root) return closest;
        int alt = closestValue(root, target);
        return abs(alt-target) > abs(closest-target)? closest: alt;
    }
};
