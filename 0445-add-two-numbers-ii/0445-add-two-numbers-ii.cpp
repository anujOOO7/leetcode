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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node1=l1;
        ListNode* node2=l2;

        stack<int> st1,st2;
        while(node1){
            st1.push(node1->val);
            node1=node1->next;
        }
        while(node2){
            st2.push(node2->val);
            node2=node2->next;
        }
        vector<int> ans;
        int carry=0;
        while(!st1.empty() && !st2.empty()){
            int sum=st1.top()+st2.top()+carry;
            st1.pop(); st2.pop();
            carry=sum/10;
            ans.push_back(sum%10);
        }
        while(!st1.empty()){
            int sum=st1.top()+carry;
            st1.pop();
            carry=sum/10;
            ans.push_back(sum%10);
        }
        while(!st2.empty()){
            int sum=st2.top()+carry;
            st2.pop();
            carry=sum/10;
            ans.push_back(sum%10);
        }
        if(carry) ans.push_back(carry);
        
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        for(int i=ans.size()-1;i>=0;i--){
            ListNode* newNode=new ListNode(ans[i]);
            temp->next=newNode;
            temp=temp->next;
        }
        return dummy->next;
    }
};