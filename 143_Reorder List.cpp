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


class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        
        //find the middle one
        ListNode *p1, *p2;
        p1 = p2 = head;
        while(p2->next && p2->next->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        //cut the list to two
        ListNode* head2 = p1->next;
        p1->next = NULL;
        
        //reverse the second list
        ListNode* temp = head2->next;
        head2->next = NULL;
        while(temp)
        {
            p1 = temp->next;
            temp->next = head2;
            head2 = temp;
            temp = p1;
        }
        ListNode *head1 = head;
        
        //merge the two lists
        while(head2)
        {
            p1 = head1->next;
            head1->next = head2;
            p2 = head2->next;
            head2->next = p1;
            head1 = p1;
            head2 = p2;
        }
    }
};
