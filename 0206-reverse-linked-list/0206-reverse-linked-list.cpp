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
    ListNode* reverseList(ListNode* head) {
        
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        
        stack<int>st;
        
        ListNode * curr= head;
        while(curr!=nullptr){
            
             st.push(curr->val);
             curr=curr->next;
            
        }
        
        curr=head;
        
         while(!st.empty()){
            
             curr->val=st.top();
             st.pop();
             curr=curr->next;
        }
        
        return head;        
          
    }
};