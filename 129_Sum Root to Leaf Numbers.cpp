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
    int sumNumbers(TreeNode* root) {
        vector<int> number;
        int num=0;
        int sum=0;
        ret(number, root, num);
        for(int i = 0; i < number.size(); i++)
        {
            sum+=number[i];
        }
        return sum;        
    }
    
    void ret(vector<int> &number, TreeNode* root, int num)
    {    
        if(root == 0 ) return;  
        num = num*10 + root->val;

        if(root->left==0 && root->right == 0)
        {        
            number.push_back(num);
            return;
        }

        ret(number, root->left, num);
        ret(number, root->right, num);
    }
};
