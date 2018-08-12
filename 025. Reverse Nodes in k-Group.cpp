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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode head(0), *h = &head;
        for(auto item: lists){
            if(item) pq.push(item);
        }
        
        while(!pq.empty()){
            ListNode* temp = pq.top();
            if(temp->next) pq.push(temp->next);
            h->next = temp;
            h=h->next;
            pq.pop();
        }
        return head.next;
    }
private:
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
};
