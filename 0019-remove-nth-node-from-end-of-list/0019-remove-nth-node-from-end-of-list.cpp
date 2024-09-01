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
    ListNode* removeNthFromEnd(ListNode* head, int n) {


        ListNode*temp=head;
        int count =0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }

        int k=count-n;

        if(count ==1 && n==1){
            return nullptr;
        }

          if(count==n){
            return head->next;
        }
        temp=head;

      

        while(temp!=nullptr){
            k--;
            if(k==0){
            temp->next=temp->next->next;}

            temp=temp->next;

        }

        return head;
        
    }
};