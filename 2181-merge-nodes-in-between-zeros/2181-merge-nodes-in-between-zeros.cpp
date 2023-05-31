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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* tmp=head;
        while(tmp->next){
            ListNode *a=tmp;
            while(tmp->next->val!=0){
                a->val+=tmp->val;
                tmp=tmp->next;
            }
            a->val+=tmp->val;
            a->next=tmp->next;
            tmp=tmp->next;
        }
        tmp=head;
        while(tmp->next->next){
            tmp=tmp->next;
        }
        tmp->next=NULL;
        return head;
    }
};