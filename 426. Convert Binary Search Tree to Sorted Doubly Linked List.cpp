/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        Node* dummy = new Node(0, NULL, NULL);
        Node* pre = dummy;
        inorder(root, pre);
        dummy->right->left = pre;
        pre->right = dummy->right;
        return dummy->right;
    }
    
private:
    void inorder(Node* root, Node*&pre){
        if(!root) return;
        inorder(root->left, pre);
        pre->right = root;
        root->left = pre;
        pre = root;
        inorder(root->right, pre);
    }
};
