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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        k%=count;
        
        while(k--){
            ListNode* temp=head,*prev,*prev2;
            while(temp){
                if(temp->next && temp->next->next==NULL) prev2=temp;
                if(temp->next==NULL) prev=temp;
                temp=temp->next;
            }
            prev->next=head;
            head=prev;
            prev2->next=NULL;
        }
        return head;
    }
};