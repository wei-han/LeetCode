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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode newHead(0);
        ListNode* curr = &newHead;
        newHead.next = head;

        while(curr->next)
        {
            bool repeat = false;
            ListNode* judge = curr->next;
            while(judge->next && judge->val == judge->next->val) {judge = judge->next; repeat =true;}
            if(repeat) curr->next = judge->next;
            else curr = curr->next;
        }
        return newHead.next;
        
        
    }
};
