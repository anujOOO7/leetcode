/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *l=head,*r=head;
        for(int i=1;i<k;i++) l=l->next;
        
        ListNode* cur=l;
        while(cur->next!=NULL){
            cur=cur->next;
            r=r->next;
        }
        int temp=l->val;
        l->val=r->val;
        r->val=temp;
        return head;
    }
};