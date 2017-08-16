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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        if(!head || !head->next) return head;
        
        ListNode *p = head;
        while(p->next)
        {
            bool change = false;
            int key = p->next->val;
            ListNode* comp = newHead;
            while(comp != p )
            {
                if(comp->next->val >= key)
                {
                    exch(comp, p);
                    change = true;
                    break;
                }
                comp = comp->next;
            }
            if(!change) p = p->next;       
        }
        return newHead->next;        
    }
    
private:    
    void exch(ListNode* p2, ListNode* p1)
    {
        ListNode* p1_post = p1->next;
        ListNode* p2_post = p2->next;
        
        p1->next = p1_post->next;
        p2->next = p1_post;
        p1_post->next = p2_post;
    }
};
