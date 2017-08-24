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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* p1 = newHead;
        ListNode* p2 = newHead->next;
        ListNode* p3 = newHead->next->next;
        while(p3)
        {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        head->next =NULL;//be careful about the newHead and head are mutually linked!!
        return p2;
    }
};
