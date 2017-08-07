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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> temp;
        
        TreeNode* curr = root;
        while(curr || !temp.empty())
        {
            if(curr)
            {
                temp.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = temp.top();
                temp.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
        
    }
};

//morris traversal
vector<int> inorderTraversal(TreeNode* root) {
    TreeNode* curNode = root;
    vector<int> nodes;
    while (curNode) {
        if (curNode -> left) {//if left child is not null
            TreeNode* predecessor = curNode -> left;
            while (predecessor -> right && predecessor -> right != curNode)
                predecessor = predecessor -> right;
            if (!(predecessor -> right)) {//if predecessor-> right == NULL
                predecessor -> right = curNode;
                curNode = curNode -> left;
            }
            else {//if predecessor-> right == curNode
                predecessor -> right = NULL;
                nodes.push_back(curNode -> val);
                curNode = curNode -> right;
            }
        }
        else {
            nodes.push_back(curNode -> val);
            curNode = curNode -> right;
        }
    }
    return nodes;
}

