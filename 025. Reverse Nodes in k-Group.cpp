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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode *pre=prehead, *cur=head, *nex;
        int count = 0;
        while(cur){
            cur=cur->next;
            count++;
        }
        
        while(count>=k){
            cur = pre->next;
            nex = cur->next;
            for(int i = 1; i<k; i++){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count-=k;
        }
        return prehead->next;
    }
};
