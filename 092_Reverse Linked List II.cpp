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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode newHead(0);
        newHead.next = head;
        ListNode* pre = &newHead;
        ListNode* start;
        n = n-m;
        
        while(--m) pre = pre->next;
        start = pre->next;
        
        while(n--)
        {
            ListNode* temp=start->next; // a node to which no pointer points is missing!!
            start->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return newHead.next;
        
        
    }
};
