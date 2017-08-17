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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A_1, *B_1;
        A_1 = headA;
        B_1 = headB;
        while(A_1 && B_1){
            A_1 = A_1->next;
            B_1 = B_1->next;
        }
        
        ListNode *A_2 = headA, *B_2 = headB;
        if(A_1 == NULL){
            while(B_1){
                B_1 = B_1->next;
                B_2 = B_2->next;
            }
        }
        else{
            while(A_1){
                A_1 = A_1->next;
                A_2 = A_2->next;
            }
        }
        
        while(A_2 != B_2){
            A_2 = A_2->next;
            B_2 = B_2->next;
        }
        
        return A_2;
    }
};
//refactory version
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2){
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}
