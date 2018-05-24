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
    ListNode* oddEvenList(ListNode* head) {
        if(!head ||!head->next) return head;
        ListNode *head1, *head0, *end1, *end0;
        head1 = head;
        end1 = head1;
        head0 = head->next;
        end0 = head0;
        ListNode* cur = end0->next;
        bool flip = true;
        while(cur){
            if(flip){
                end1->next = cur;
                end1 = end1->next;
                cur = cur->next;
            }
            else{
                end0->next = cur;
                end0 = end0->next;
                cur=cur->next;
            }
            flip= !flip;            
        }
        end1->next = head0;
        end0->next = NULL;
        return head1;
    }
};
