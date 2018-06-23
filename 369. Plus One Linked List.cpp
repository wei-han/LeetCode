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
    ListNode* plusOne(ListNode* head) {
        ListNode* first = new ListNode(0);
        first->next = head;
        ListNode *i = first, *j = first;
        
        while(i->next){
            i = i->next;
            if(i->val !=9) j = i;
        }
        
        j->val +=1;
        j = j->next;
        
        while(j){
            j->val = 0;
            j = j->next;
        }
        
        if(first->val == 0) return first->next;
        return first;
        
    }
};
