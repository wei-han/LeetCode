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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *begin, *end, *tempb, *tempe;
        begin = end = head;
        
        while(end->next)
        {
            end = end->next;
        }
        
        while(!(begin == end || begin->next==end))
        {
            tempb = begin->next;
            begin->next = end;
            end->next = tempb;
            tempe = tempb;
            while(tempe->next != end)
            {
                tempe = tempe->next;
            }
            begin = tempb;
            end = tempe;            
        }
        end->next = NULL;
        
        
    }
}
