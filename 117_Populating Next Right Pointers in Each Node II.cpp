/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == 0) return;
        TreeLinkNode *head, *tail;
        head = 0;
        tail = 0;
        
        while(root)
        {
            if(root->left)
                if(tail) tail = tail->next = root->left;
                else head = tail = root->left;
            
            if(root->right)
                if(tail) tail = tail->next = root->right;
                else head = tail = root->right;
            
            root = root->next;
            if(!root)
            {
                root = head;
                head =  tail = 0;
            }
        }
        
    }
};
