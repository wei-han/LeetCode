//java solution using reference
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int rob(TreeNode root) {
        return Math.max(sub(root)[0], sub(root)[1]);
    }
    
    int[] sub(TreeNode root){
        int[] res = new int[2];
        if(root== null) return res;
        
        int[] left = sub(root.left);
        int[] right = sub(root.right);
        
        res[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        res[1] = root.val + left[0] + right[0];
        
        return res;
    }
}

//cpp solution;
//cannot assign pointer to array, so change the array within the function
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
    int rob(TreeNode* root) {
        vector<int> res(2);
        sub(root, res);
        return max(res[0], res[1]);
    }
    
    void sub(TreeNode* root, vector<int> &res){
             
        if(root == NULL){
            res[0] =0;
            res[1] =0;
            return;
        }
        
        vector<int> left(2);
        sub(root->left, left);
        vector<int> right(2);
        sub(root->right, right);

        res[0] = max(left[0], left[1])+ max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];
    } 
};
