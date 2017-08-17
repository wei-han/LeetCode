/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        push_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !minstack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* minnum = minstack.top();
        minstack.pop();
        push_left(minnum->right);
        
        return minnum->val;
    }
private:
    stack<TreeNode*> minstack;
    
    void push_left(TreeNode* root){
        while(root){
            minstack.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
