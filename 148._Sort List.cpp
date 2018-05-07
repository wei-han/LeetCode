//use merge sort

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !(head->next)) return head;
        
        int len = 0;
        ListNode* cur = head;
        while(cur){
            len++;
            cur = cur->next;
        }
        
        ListNode newNode(0);
		newNode.next = head;
        
        ListNode *left, *right, *tail;
        
        for(int step = 1; step < len; step = step*2){
            cur = newNode.next;
            tail = &newNode;
            
            while(cur){
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);                
            }
        }
        return newNode.next;
    }
private:
    ListNode* split(ListNode* node, int step){
        for(int i = 1; node&& i < step; i++) node = node->next;
        
        if(!node) return NULL;
        ListNode* res = node->next;
        node->next = NULL;
        return res;
    }
    
    ListNode* merge(ListNode* left, ListNode* right, ListNode* tail){
        while(left && right){
            if(left->val > right->val){
                tail->next = right;
                tail = right;
                right = right->next;
            }
            else{
                tail->next = left;
                tail = left;
                left = left->next;
            }
        }
        tail->next = left ? left : right;
        while(tail->next) tail = tail->next;
        return tail;
    }
};
