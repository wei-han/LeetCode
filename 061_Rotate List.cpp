//make it a circle!!
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        ListNode *newHead, *tail;
        newHead = tail = head;
        int len=1;
        
        while(tail->next)
        {
            tail = tail->next;
            len++;
        }
        
        tail->next = head;
        
        if (k%=len)
        {
            for( int i = 0; i < len - k; i++) tail = tail->next;
        }
        newHead = tail->next;
        tail->next = NULL;
        
        return newHead;
        
    }
};
